In a game the player will use **N** coins numbered from **1** to **N**, and all the coins will be facing in "Same direction" (Either Head or Tail), which will be decided by the player before starting of the game.

The player needs to play **N** rounds. In the **k-th** round the player will flip the face of the all coins whose number is less than or equal to **k**. That is, the face of coin **i** will be reversed, from Head to Tail, or, from Tail to Head, for **i≤k**.

Karan needs to guess the total number of coins showing a particular face after playing **N** rounds. Karan really becomes quite fond of this game COIN FLIP so Karan plays **G** times. Please help the Karan to find out the answer.

# Input :
The first line of input contains an integer **T**, denoting the number of test cases. Then T test cases follow.

The first line of each test contains an integer **G**, denoting the number of games played by Karan. Each of the following **G** lines denotes a single game, and contains 3 space-separated integers **I, N, Q,** where **I** denotes the initial state of the coins, **N** denotes the number of coins and rounds, and **Q**, which is either **1**, or **2** as explained below.

Here **I=1** means all coins are showing Head in the start of the game, and **I=2** means all coins are showing Tail in the start of the game. **Q=1** means Karan needs to guess the total number of coins showing Head in the end of the game, and **Q=2** means Karan needs to guess the total number of coins showing Tail in the end of the game.

# Output :
For each game, output one integer denoting the total number of coins showing the particular face in the end of the game.

# Constraints :
**1≤T≤10** <br>
**1≤G≤2000** <br>
**1≤N≤10** <br>
**1≤I≤2** <br>
**1≤Q≤2** <br>