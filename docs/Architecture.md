\# Project Criticli: Architecture \& Technical Design



\## 1. System Vision

Criticli is a high-performance CLI tool designed for Game Masters of the Daggerheart TTRPG. The system is built using \*\*C++23\*\* to leverage modern functional paradigms, compile-time safety (Concepts), and the new standard library features for expressive, readable code.



\## 2. Component Decomposition



The system is partitioned into four primary domains to ensure a clean separation of concerns:



\### A. The Core Engine (Mechanics \& Probability)

\* \*\*Responsibility:\*\* Handling the "Duality Dice" logic (1d12 Hope + 1d12 Fear).

\* \*\*Design Decision:\*\* We use `std::expected` for roll results. An action roll is not just a number; it is a complex outcome that can fail due to input constraints.

\* \*\*C++23 Feature:\*\* `std::expected<RollResult, ErrorCode>`. This replaces the C++11 pattern of returning a `bool` and using an out-parameter.



\### B. The State Machine (The Gameplay Loop)

\* \*\*Responsibility:\*\* Managing the "Spotlight" holder, tracking the GM Fear pool, and transitioning between "In Danger" and "Downtime" scenes.

\* \*\*Design Decision:\*\* Use a centralized `SessionManager` to track the "Spotlight" as a state.

\* \*\*C++23 Feature:\*\* `std::print` and `std::format` for real-time audit logging and UI updates.



\### C. The Entity System (PC \& Adversary Management)

\* \*\*Responsibility:\*\* Tracking Hit Points, Stress, Armor Slots, and Conditions (Hidden, Vulnerable, etc.).

\* \*\*Design Decision:\*\* Entities are modeled using a Component-based approach. PC stats like Evasion and Damage Thresholds are validated via \*\*C++20/23 Concepts\*\* to ensure type safety during modifier arithmetic.



\### D. The Persistence Layer (Data Storage)

\* \*\*Responsibility:\*\* Saving/Loading party rosters and session recaps.

\* \*\*C++23 Feature:\*\* Utilizing `std::views` to filter and transform character data (e.g., "Show only PCs with 0 Stress remaining") before serialization.



---



\## 3. Deep Dive: Why C++23?



\### Error Handling with `std::expected`

In Daggerheart, rolls often require specific preconditions (e.g., "Must have 1 Hope to Help an Ally"). 

\* \*\*Old Way (C++11):\*\* Return a magic number like `-1` or throw an exception.

\* \*\*Modern Way (C++23):\*\* ```cpp

&nbsp;   std::expected<RollResult, std::string> perform\_tag\_team(PC\& a, PC\& b) {

&nbsp;       if (a.hope < 3) return std::unexpected("Insufficient Hope");

&nbsp;       return RollResult{...};

&nbsp;   }

&nbsp;   ```



\### Modern Text Formatting

`std::print` (C++23) is used throughout the CLI. It provides the safety of `iostream` with the performance and clean syntax of `printf`. This allows us to render complex combat logs (e.g., "Critical Success: Gain 1 Hope") without the "chevron soup" of `std::cout`.



\### Range-Based Mechanics

When the GM spends Fear to "Spotlight" additional adversaries, we use \*\*Ranges and Views\*\* to lazily evaluate which adversaries are eligible for action based on their distance (Melee, Close, etc.).



---



\## 4. Implementation Roadmap



1\.  \*\*Level 0: The Dice Engine.\*\* Build the Duality Dice roller and outcome classifier.

2\.  \*\*Level 1: Entity Models.\*\* Implement the PC and Adversary structs with Threshold/Armor logic.

3\.  \*\*Level 2: The Spotlight Controller.\*\* Build the logic for passing the spotlight and managing the GM Fear pool.

4\.  \*\*Level 3: The CLI Loop.\*\* Implement the user-facing command parser and `std::print` output.

5\.  \*\*Level 4: Rests \& Downtime.\*\* Add support for Short/Long rests and the Death Move chooser.