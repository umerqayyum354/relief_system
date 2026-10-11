# Relief Supply Distribution System

A C++ program that calculates a **need score** for each emergency request and decides how to distribute trucks and supply packs.

## Need Score Formula

```
Need Score = Damage + Families Affected + Route + Flood Warning + Medical Need + Previous Aid
```

The score ranges from 0 to 100.

| Factor | Condition | Points |
|---|---|---|
| Damage level | Low | 10 |
| | Medium | 20 |
| | High | 30 |
| Families affected | 0 | 0 |
| | 1 - 10 | 10 |
| | 11 - 50 | 15 |
| | 51 - 100 | 20 |
| | 101 - 150 | 25 |
| | 151 - 200 | 30 |
| | More than 200 | 35 |
| Access route | Open | +5 |
| | Damaged | -5 |
| Flood warning | Yes | +10 |
| | No | 0 |
| Medical need | Yes | +15 |
| | No | 0 |
| Previous aid | Received | -5 |
| | Not received | +5 |

## Reason for Each Weight

| Factor | Reason |
|---|---|
| Damage level | It is the most direct measure of how serious the situation is, so it has a large weight (up to 30). |
| Families affected | More affected families need more supplies, so the points increase with the number of families (up to 35). |
| Access route | A damaged route makes delivery harder, so it lowers the score slightly. It does not cancel the need, so the effect is small (+5 / -5). |
| Flood warning | A warning means the situation may get worse soon, so it adds 10 points. |
| Medical need | Medical need can mean risk to life, so it gets a high bonus (15 points). |
| Previous aid | Areas that already received help are lower priority than areas that received none (-5 / +5). |

## Actions and Resources

These actions and resource amounts are fixed by the assignment.

| Action | Trucks | Supply Packs |
|---|---|---|
| A. Full Relief | 2 | 50 |
| B. Standard Relief | 1 | 30 |
| C. Emergency Kit Only | 1 | 10 |
| D. Defer / Monitor | 0 | 0 |

## Decision Rules

| Need Score | Preferred Action |
|---|---|
| 65 or more | A. Full Relief |
| 45 to 64 | B. Standard Relief |
| 25 to 44 | C. Emergency Kit Only |
| Less than 25 | D. Defer / Monitor |

**Resource checks:** Before an action is chosen, the program checks that both trucks **and** supply packs are enough. Resources are only subtracted when relief is actually sent, so they can never become negative.

**Downgrading:** If the preferred action cannot be afforded, the program tries the next smaller action:

- Full Relief -> Standard Relief -> Emergency Kit Only
- Standard Relief -> Emergency Kit Only
- Emergency Kit Only -> no smaller action

**Deferred vs Not Served:**

| Status | When it happens |
|---|---|
| Deferred / Monitored | The score is below 25, so waiting is the decision. |
| Not Served | The score needs help, but no action can be afforded with the remaining resources. |

Both use 0 trucks and 0 supply packs.

## Flowcharts

Flowchart 1 shows the main flow of the program (inputs, score, action, summary):

![Flowchart 1: Main flow](flowchart1_main.png)

Flowchart 2 shows how the action is chosen and how resources are checked:

![Flowchart 2: Decision and resource checks](flowchart2_decision.png)

## Test Set 1: Sufficient Resources

Starting resources: **5 trucks, 120 supply packs**

| Request | Damage | Families | Route | Flood Warning | Medical Need | Previous Aid | Score | Action | Trucks Used | Packs Used | Remaining Trucks | Remaining Packs |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | | | | | | | | | | | | |
| 2 | | | | | | | | | | | | |
| 3 | | | | | | | | | | | | |
| 4 | | | | | | | | | | | | |
| 5 | | | | | | | | | | | | |

**Summary:** Served: __ , Deferred: __ , Not Served: __

## Test Set 2: Insufficient Resources

Starting resources: **__ trucks, __ supply packs**

| Request | Damage | Families | Route | Flood Warning | Medical Need | Previous Aid | Score | Action | Trucks Used | Packs Used | Remaining Trucks | Remaining Packs |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | | | | | | | | | | | | |
| 2 | | | | | | | | | | | | |
| 3 | | | | | | | | | | | | |
| 4 | | | | | | | | | | | | |
| 5 | | | | | | | | | | | | |

**Summary:** Served: __ , Deferred: __ , Not Served: __

## Group Member Contributions

| Member | Contribution |
|---|---|
| Muhammad Umer Qayyum | Wrote the C++ code and compiled the Word document |
| Ali Waris | Wrote the README (Markdown) and made the flowcharts |

## GitHub Repository

https://github.com/umerqayyum354/relief_system

## AI Use Note

We wrote the program ourselves and used AI to help us understand some concepts and improve our work. What we learned and used AI for:

1. **Using constants:** We understood that writing values directly in the code makes it messy and hard to manage. So we defined a separate `const` for every value, which makes the code cleaner and easier to change.
2. **`cin.fail()`:** We learned how to handle wrong input (like typing letters instead of numbers) using `cin.fail()`, `cin.clear()` and `cin.ignore()`, so the program does not go into an infinite loop.
3. **Deferred vs Not Served:** We used AI to understand the difference between these two concepts. Deferred means waiting is the decision, while Not Served means help was needed but no resources were available.
4. **Markdown:** We learned markdown and used AI to improve the syntax of this README.
5. **Rubric conversion:** We used AI to convert the rubric and scoring sheet from the assignment PDF into a Word table.
