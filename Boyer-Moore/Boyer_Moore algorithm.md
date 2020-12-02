# Algorithm for `Boyer Moore`
1. Start 
2. search function call
    1. declare m and n as lengths of pattern and text
    2. dynamic memeory allocation for array tab
    3. call to the table function 
        1. assign the tab initially as -1
        2. assign the taba as pattern
    4. declare s and flag with value 0
    5. while s <=(n - m) do from 2.6 to 2.13
    6. declare j as m-1
    7. while j >= 0 and pat[i] == txt[s+j] do j--
    8. if j < 0 then do from 2.9 to 2.11
    9. flag++
    10. return true
    11. s += (s+m < n)? m-tab[txt[s+m]]
    12. else do s+ = max(1, j-tab[txt[s+j]])
    13. end while
    14. check if flag == 0 return false
3. End