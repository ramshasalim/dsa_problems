class Solution {
public:
int maxProfit(vector<int>& prices) {
int n=prices.size();

// b = lowest price we have seen so far
// We want to buy at the lowest price and sell later at a higher price
int maxi=0;
int b=prices[0];

for(int i=1;i<n;i++){

// If today's price is higher than our buying price,
// calculate the profit if we sell today
if(prices[i]>b){
maxi=max(maxi,prices[i]-b);
}

// Keep the smallest price seen so far as our best buying price
b=min(prices[i],b);

}

// If no profitable transaction was possible, return 0
if(maxi<=0){
return 0;
}

return maxi;

}
};
