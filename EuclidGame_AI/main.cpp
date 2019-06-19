#include<bits/stdc++.h>

using namespace std;


int ini1,ini2,need,temp1,temp2,dp[100][100];
int minimax(int n, int m, bool maximizing){
    if(m>n)
        swap(m,n);
    if(m==0 || n==0){
        if(maximizing)
            return -1;
        else
            return +1;
    }

    if(m==1 || n==1){
        if(maximizing)
            return +1;
        else
            return -1;
    }

    int loop=n/m;

    if(maximizing){
        int mxval=-1e9;

        for(int i=1; i<=loop; i++){
            int eval=minimax(n-i*m,m,false);

            if(eval>mxval){
                mxval=eval;
                //need=i;
            }
        }
        return mxval;
    }

    else{
        int mnval=1e9;

        for(int i=1; i<=loop; i++){
            int eval=minimax(n-i*m,m,true);

            if(eval<mnval){
                mnval=eval;

                dp[n][m]=i,dp[m][n]=i;
               // cout<<"need: "<<need<<' '<<eval<<' '<<n<<' '<<m<<endl;
            }
        }
        return mnval;
    }
}

int main()
{
    cout<<"#########################The Euclid Game#########################\n";
    cout<<"Enter two initial number a>b:";
    cin>>ini1>>ini2;
    int step=0;

    while(1){
        cout<<"Remaining value :"<<ini1<<' '<<ini2<<endl;
        if(step%2==0){
            if(ini1==0 || ini2==0){
                cout<<"\n=>Computer lose."<<endl;

                break;
            }

            if(ini1==1 || ini2==1){
                cout<<"\n=>You lose."<<endl;

                break;
            }


            cout<<"\nComputer's turn:---- "<<endl;
            int ans=minimax(ini1,ini2,false);
            ini1=ini1-dp[ini1][ini2]*ini2;
            if(ini1<ini2)
                swap(ini1,ini2);
        }

        else{
            if(ini1==0 || ini2==0){
                cout<<"\n=>You lose."<<endl;

                break;
            }

            if(ini1==1 || ini2==1){
                cout<<"\n=>Computer lose."<<endl;

                //break;
            }
            cout<<"\nYour turn:---- "<<endl;

            cout<<"Please enter x(b*x<=a):";

            int val;

            cin>>val;

            ini1=ini1-ini2*val;

            if(ini1<ini2)
                swap(ini1,ini2);
        }
        step++;
    }
    return 0;
}
