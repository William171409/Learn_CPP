// You are playing the following Nim Game with your friend:

// Initially, there is a heap of stones on the table.
// You and your friend will alternate taking turns, and you go first.
// On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
// The one who removes the last stone is the winner.
// Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.


    bool canWinNim(int n) {
       return n%4!=0; 
    }

// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.




    bool checkWin(int ans,int total){
	   //ans=max player 1 can score and total=sum of all elements in the array
	   //so, player2's score=total-player1's score . ie:-total-ans;
	   //According to question player1's score should be greater than or equal to player2's score. 
	   return ans>=total-ans;
    }
    int maxScore(vector<int>&A,int total,int i,int j){
        if(i>j) //our base condition
            return 0;
      return total-min(maxScore(A,total-A[i],i+1,j),maxScore(A,total-A[j],i,j-1)); //max the current player can get is total-maxm the next player can get.
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int total=0; 
		//total=sum of all elements in the array
        for(auto x:nums)
            total+=x;
        return checkWin(maxScore(nums,total,0,nums.size()-1),total);
    }


