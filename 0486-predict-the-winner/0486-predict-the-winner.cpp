class Solution {
public:
bool playgame(int turn, int s1, int s2, int i, int j, vector<int>& nums) {
        // base case
        if (i > j) {
            return s1 >= s2;
        }

        if (turn) {
            // for player 1 to win, he should win in atleast one future
            return playgame(0, s1 + nums[i], s2, i + 1, j, nums) 
                || playgame(0, s1 + nums[j], s2, i, j - 1, nums);
        }
        // no matter what player 2 chooses, player 1 has to win, so thats why &&
        return playgame(1, s1, s2 + nums[i], i + 1, j, nums) 
            && playgame(1, s1, s2 + nums[j], i, j - 1, nums);

    }
    bool predictTheWinner(vector<int>& nums) {
        return playgame(1, 0, 0, 0, nums.size() - 1, nums);
    }
};