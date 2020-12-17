#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>

using namespace std;

int max(int a, int b){
      return (a > b) ? a : b;
}

int knapSack_RE(int W, int wt[], int val[], int n){
      if(n == 0 || W == 0)
            return 0;

      if(wt[n-1] > W)
            return knapSack_RE(W, wt, val, n-1);

      else
            return max(val[n-1] + knapSack_RE(W - wt[n-1], wt, val, n-1), knapSack_RE(W, wt, val, n-1));
}

int knapSack_DP(int W, int wt[], int val[], int n){
      int K[n+1][W+1];

      for(int i = 0; i <= n; i++){
            for(int w = 0; w <= W; w++){
                  if(i==0 || w==0)
                        K[i][w] = 0;
                  else if(wt[i-1] <= w)
                        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
                  else
                        K[i][w] = K[i-1][w];
            }
      }
      return K[n][W];
}

int main(){
      const int size = 100;
      int val[size], wt[size];
      int n = 0, W = 100, DP, Rec;
      float total_time_1, total_time_2;

      for(int i = 10; i <= 60; i = i + 5){
            n = i;
            cout << "N=" << i << "     " << "W=" << W << "     ";
            srand(time(NULL));

            for(int j = 0; j < i; j++){
                  val[j] = rand() % 50 + 1;
                  wt[j] = rand() % 30 + 1;
            }

            clock_t start_1, end_1;
            start_1 = clock();
            DP = knapSack_DP(W, wt, val, n);
            end_1 = clock();

            clock_t start_2, end_2;
            start_2 = clock();
            Rec = knapSack_RE(W, wt, val, n);
            end_2 = clock();

            float time_taken_1 = float(end_1 - start_1) / CLOCKS_PER_SEC;
            total_time_1 = total_time_1 + time_taken_1;

            float time_taken_2 = float(end_2 - start_2) / CLOCKS_PER_SEC;
            total_time_2 = total_time_2 + time_taken_2;

            cout << "Rec time = " << fixed << total_time_2 << "     ";
            cout << "DP time = " << fixed << total_time_1 << "     ";
            cout << "max Rec = " << Rec << "     ";
            cout << "max DP = " << DP << endl;
      }

      return 0;
}
