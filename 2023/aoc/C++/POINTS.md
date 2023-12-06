# Day 4

## Part 2

This is actually difficult for me. I am kinda dumb you see. My idea right now is to create a vector with 220 (lines.size() so it works with different inputs as well) values all containing 1. This vector is to store the amount of copies + original of any given card. Whenever we duplicate cards, I run through a vector the number of winning numbers and add the amount in the vector for the card at hand to the next few cards. Ex: vector = { 1, 2, 3, 2, 1, 7 }; We are in card 2, find 3 winning numbers, so the vector becomes { 1, 2, 5, 4, 3, 7 }. The vector contains everything so you pull from vector and use values to add copy cards. In the end we can add all the values in the vector for the answer of total number of scratchcards. We have to define the vector beforehand using a loop or else it gets tuff.

Okay after the short brainstorming from above, I realized it was easy to implement and finished in 3 minutes. No errors - one of the first times lol.

# Day 5

For the day 5 solution I have thought of a program that has a function with four inputs, the three numbers given on each line, and using those inputs and a vector with all the seed numbers / initial numbers we will convert each one one by one if it is in the given range.
