## Summary
- [x] Turned based combat function (A)
- [x] Add speed stat (A)
- [ ] Add xp (A)
- [x] Display stats command (B)
- [ ] Map command (B)
- [x] HP during combat (C)

## TurnBasedCombat Function:
### A.
- Takes in 2 arguments 
1. Player
2. Enemy

- Who goes first?? ( Add speed stat? )
- Battle start :
- Ex. Player start
1. Options printed ( refer to D. )
2. After player turn
3. Print out Enemy attack ( or decision if decided to add a random deciding pattern for enemies ex. attacking or defending )
4. Loop until either one reaches 0 hp
5. If player won receive gold by current player gold + gold drop value of enemy.
6. ( Consider adding player xp? for levelling up stats )
7. If loss/died loop back to start (path0)
8. If died proportional penalty or complete reset?

- Options :
1. Attack ( Direct dmg or total dmg - enemy defense if added )
2. Defend ( Add defense stat? )
3. Run ( Only possible if have higher speed? )

### B.
Cool idea
1. Add "stat" command. Displays current player stat. // Finished
2. Add "map" command. Display current player position in the paths ex. could be tree style.

Ex.       
               .- [   ] -. 
            /      |      \
         [   ]  [   ]  [   ]

Design is subject to change 

### C.
- Add HP bar during combat