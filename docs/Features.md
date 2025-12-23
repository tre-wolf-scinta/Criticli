# Features

- Create a session (date, party roster, current location/scene, safety notes, recap, session notes)

- Track the current “spotlight” holder and quickly hand spotlight to another PC or to the GM based on fiction or triggered mechanics 

- Optional spotlight token tracker mode (set tokens per PC, decrement on action, prevent spotlight going to PCs with 0 tokens, auto-refill when all are empty) 

- Run the core gameplay loop workflow (set the scene, answer questions, trigger rolls when needed) 

- Make an action roll (roll Hope d12 + Fear d12, add modifiers, compare to Difficulty) 

- Auto-classify action roll outcomes (Success with Hope, Success with Fear, Failure with Hope, Failure with Fear) 

- Apply outcome side-effects (gain Hope on Hope outcomes, GM gains Fear on Fear outcomes, spotlight swings to GM on failures) 

- Handle Critical Success (matching Duality Dice) including bonus success, gain Hope, clear 1 Stress, and treat as “with Hope” 

- Let GM set Difficulty and optionally reveal it, plus record “what failure costs” before the roll 

- Build a dice pool with modifiers that must be declared before rolling (Experiences, advantage die, other add-ons) 

- Make a Reaction Roll (for defensive/support situations and for group actions) 

- Run a Group Action (nominate leader; others roll reaction rolls with appropriate traits; leader makes the action roll) 

- Help an Ally (spend 1 Hope, roll a d6 advantage die for the ally to add; if multiple sources of advantage exist, use the highest) 

- Initiate a Tag Team Roll (spend 3 Hope; track “once per session” initiations per PC) 

- Resolve Tag Team attack success (both roll damage, add together as one source; choose damage type if different) 

- Track the GM’s Fear pool (gain Fear on “with Fear” outcomes and when rules grant Fear) 

- Spend Fear to activate adversary/environment Fear features and other GM moves 

- When play passes to the GM, spotlight an adversary and choose an adversary option set (move + standard attack, use an adversary action, clear a condition, sprint, or fiction-appropriate action) 

- Spend additional Fear to spotlight additional adversaries in the same GM spotlight sequence 

- Manage PC Evasion (store each PC’s current Evasion and use it as the Difficulty for rolls made against that PC) 

- Make Attack Rolls (trait determined by weapon/spell; unarmed uses Strength or Finesse; difficulty is target’s Difficulty/Evasion as applicable) 

- Make Damage Rolls (support xdy+modifier expressions; handle Spellcast-based dice counts; handle weapon Proficiency multiplying dice) 

- Compute Critical Damage on a crit attack (normal roll plus the maximum possible result of the damage dice) 

- Support physical vs magic damage types, plus mixed damage logic 

- Apply resistance and immunity (including “must be resistant/immune to both” for mixed damage) 

- Support direct damage that cannot be reduced by marking Armor Slots 

- Handle multi-target attacks (one attack roll and one damage roll, applied per target) 

- Combine simultaneous damage from multiple sources before comparing to thresholds 

- Track Hit Points and apply damage thresholds (mark 1/2/3 HP based on Major/Severe thresholds) 

- Optional massive damage rule (damage ≥ 2x Severe threshold marks 4 HP) 

- Track armor, Armor Score, Armor Slots, and armor-based Major/Severe thresholds 

- Reduce incoming damage by marking Armor Slots (1 slot reduces HP marked by 1; cannot if Armor Score is 0) 

- Track Stress (mark/clear Stress; enforce “can’t use moves requiring Stress if all Stress is marked”) 

- Apply Stress edge cases (if you must mark Stress but can’t, mark 1 HP instead) 

- Apply “last Stress” effect (become Vulnerable until at least 1 Stress is cleared) 

- Track standard conditions (Hidden, Restrained, Vulnerable) with their mechanical effects 

- Apply Hidden rules (disadvantage on rolls against Hidden; clear Hidden when revealed or after making an attack) 

- Apply Restrained rules (can’t move, can still act from current position) 

- Apply Vulnerable rules (all rolls targeting are with advantage) 

- Support temporary tags and special conditions including “how to clear” workflows (PC clears via successful action roll; adversary clears by spending their spotlight) 

- Track positioning using abstract ranges (Melee, Very Close, Close, Far, Very Far, Out of Range) 

- Enforce movement rules while in danger (move within Close as part of an action roll; Agility Roll to safely move farther or reposition when not already rolling) 

- Handle “move into Melee” constraints from Far/Very Far (requires Agility Roll to safely move into Melee) 

- Handle adversary movement baselines (Close range for free as part of an action; Very Far as a separate action) 

- Model line of sight and cover (cover causes disadvantage; no line of sight means no ranged attack) 

- Model area-of-effect targeting constraints (targets must be within Very Close of a single origin point unless stated otherwise) 

- Support optional “defined ranges” grid mode for tactical play 

- Run rests (short rest vs long rest; enforce “after three short rests, next must be a long rest”) 

- Apply interrupted rest rules (interrupted short rest grants no benefits; interrupted long rest grants short rest benefits only) 

- Execute downtime moves (each PC picks up to two moves per rest; allow selecting the same move twice) ([Daggerheart][14])

- Short rest downtime moves (Tend to Wounds 1d4+Tier HP; Clear Stress 1d4+Tier; Repair Armor 1d4+Tier slots; Prepare for Hope gains including group Prepare) 

- Long rest downtime moves (Tend to All Wounds; Clear All Stress; Repair All Armor; Prepare; Work on a Project with countdown) 

- Move domain cards between loadout and vault for free during rests 

- Refresh per-rest and per-long-rest uses and expire “until next rest” effects appropriately 

- Apply downtime consequences to GM (gain Fear on rests; advance a long-term countdown on long rest) 

- Create and track countdowns (for projects and other long-term clocks), advance them automatically or via action rolls as the GM decides 

- When a PC marks their last HP, trigger the Death move chooser 

- Resolve Death: Blaze of Glory (final action auto critically succeeds with GM approval, then die) 

- Resolve Death: Avoid Death (unconscious state rules; wake on healing or long rest; roll Hope die for scar check; permanently cross out a Hope slot on scar; journey ends if last Hope slot crossed out)

- Resolve Death: Risk It All (roll Duality Dice; Hope higher clears HP/Stress equal to Hope die; Fear higher dies; matching dice stays up but clears nothing)

- Track Hope slots and current Hope count per PC, including permanent “crossed out” Hope slots from scars 

- Track and spend Hope for core uses (Utilize an Experience, Help an Ally, use a Hope Feature, initiate a Tag Team Roll) 

- Utilize an Experience (spend Hope before the roll to add its value as a modifier when it applies) 

- Maintain a searchable reference for rules sections a GM hits constantly (Making moves, Combat, Attacking, Maps/Movement, Conditions, Downtime, Death) ([Sean’s homepage][16]

- Manage adversaries (create/import stat blocks, track HP/thresholds/conditions, and execute adversary spotlight actions) ([Daggerheart S

- Manage scenes with quick toggles for “in danger/under pressure” to drive movement and roll expectations (

- Maintain an audit log of rolls and spend events (who rolled what, Hope/Fear outcome, what was spent, what changed in-fiction) (

