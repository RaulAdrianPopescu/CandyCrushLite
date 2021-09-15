# CandyCrushLite

Irina discovered a new computer game! The screen displays a sequence of N number of colored globes. The colors are represented by numbers ranging from 0 to 9.
A sub-sequence is composed of at least 3 identically colored globes, arranged one after the other. Irina, as the player, has a special bow at her disposal. Whenever she looses an arrow at a subsequence,
it is destroyed and the elements following that subsequence shift in its place. The game is won once there are no more globes in the sequence or there are no more subsequences.

While Irina is not necessarily the best at this game, she devised the following strategy in order to maximize her score:

1. She will only fire upon the largest sub-sequence found on the screen.
2. If there are multiple sub-sequences of the same maximal size, she will fire only on the one furthermost left.

Example:

-We are provided the following sequence:
      5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 4 7
-The sub-sequence of 4s, being the largest one of the sequence will be removed, resulting in the following sequnce:
      5 1 3 3 2 2 2 2 3 1 1 5 6 7
-Now, the largest sub-sequence is the one formed by 2s, after its deletion we get the following sequence:
      5 1 3 3 3 1 1 5 6 7
-After the deletion of the sub-sequence made up of 2s, we now have a sub-sequence of 3s as the largest one, meaning that it will be removed:
      5 1 1 1 5 6 7
-Now, for the 1s:
      5 5 6 7
-In the end, our sequence will be the following:
      5 5 6 7
