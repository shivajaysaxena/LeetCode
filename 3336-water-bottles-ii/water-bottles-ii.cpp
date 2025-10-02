class Solution {
public:
    int maxBottlesDrunk(int numBot, int numEx) {
        int empBot=numBot;
        int bckBot=numBot;
        numBot=0;
        while(empBot >= numEx){
            empBot-=numEx;
            numEx+=1;
            empBot+=1;
            bckBot+=1;
        }
        return bckBot;
    }
};