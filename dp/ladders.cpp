#include<iostream>
using namespace std;

//here sum represents number of ways
int ladders_topdown(int n,int k,int dp[]){

if(n==0){
    return 1;
}
//if dp[n] is not zero yahi se return krdege
if(dp[n]!=0){
    return dp[n];
}
int sum=0;
for(int i=1;i<=k;i++){

    if(n-i>=0)
    sum+=ladders_topdown(n-i,k,dp);

    //it's valid here but not the best solution
    //becoz dp[n] will keep on updating so it's better
    //to write out side the loop
    // dp[n]=sum;
}

 dp[n]=sum;
return sum;

}

int ladders_bottom_up(int n,int k){
    int dp[100]={0};

    dp[0]=1;//start case
    for(int i=1;i<=n;i++){
        //dp[i]=0 is redundact
        for(int j=1;j<=k;j++){
            if(i-j>=0)
            dp[i]+=dp[i-j];
        }
    }
    //see bottom up
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}


//most optimised approach
int ladders_optimised(int n,int k){
    int dp[100]={0};

    dp[0]=dp[1]=1;
    //here i-k<0 so handling it separately
    //and as i-k<0 so we can take all elments
    //and we know sum till i-2th index equals to
    // value at i-1th index. 
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }
     for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }

    //see bottom up by printing
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];

}
int main(){
int n,k;
cin>>n>>k;


int dp[100]={0};

cout<<ladders_topdown(n,k,dp)<<endl;
cout<<ladders_bottom_up(n,k)<<endl;
cout<<ladders_optimised(n,k)<<endl;

}
