

#include <stdio.h>
#define MAX 100
typedef struct Job {
	char id[5];
	int deadline;
	int profit;
} Job;
void jobSequencingWithDeadline(Job jobs[], int n);
    int minValue(int x, int y) {
    if(x < y) return x;
    return y;
}
int main(void) {
    int i, j;
    Job jobs[5] = {
    {"j1", 2,  60},
    {"j2", 1, 100},
    {"j3", 3,  20},
    {"j4", 2,  40},
    {"j5", 1,  20},
    };
    Job temp;
    int n = 5;
    for(i = 1; i< n; i++) {
        for(j = 0; j < n - i; j++) {
            if(jobs[j+1].profit> jobs[j].profit) {
            temp = jobs[j+1];
            jobs[j+1] = jobs[j];
            jobs[j] = temp;
            }
        }
    }
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(i = 0; i< n; i++) {
        printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    jobSequencingWithDeadline(jobs, n);
    return 0;
}
void jobSequencingWithDeadline(Job jobs[], int n) {
    int i, j, k, maxprofit;
    int timeslot[MAX];
    int filledTimeSlot = 0;
    int dmax = 0;
    for(i = 0; i< n; i++) {
        if(jobs[i].deadline>dmax) {
            dmax = jobs[i].deadline;
        }
    }
    for(i = 1; i<= dmax; i++) {
        timeslot[i] = -1;
    }
    printf("dmax: %d\n", dmax);
    for(i = 1; i<= n; i++) {
        k = minValue(dmax, jobs[i - 1].deadline);
        while(k >= 1) {
            if(timeslot[k] == -1) {
                timeslot[k] = i-1;
                filledTimeSlot++;
                break;
            }
            k--;
        }
        if(filledTimeSlot == dmax) {
            break;
        }
    }
    printf("\nRequired Jobs: ");
    for(i = 1; i<= dmax; i++) {
        printf("%s", jobs[timeslot[i]].id);
        if(i<dmax) {
            printf(" --> ");
        }
    }
    maxprofit = 0;
    for(i = 1; i<= dmax; i++) {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);
}


// Output: 
//        Job   Deadline     Profit
//         j2          1        100
//         j1          2         60
//         j4          2         40
//         j3          3         20
//         j5          1         20
// dmax: 3
// Required Jobs: j2 --> j1 --> j3
// Max Profit: 180


//Easy Solution 


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Jobs {
   char id;
   int dead;
   int profit;
} Jobs;

int compare(const void* a, const void* b){
   Jobs* temp1 = (Jobs*)a;
   Jobs* temp2 = (Jobs*)b;
   return (temp2->profit - temp1->profit);
}

int min(int num1, int num2){
   return (num1 >= num2) ? num2 : num1;
}
int main(){
   Jobs arr[] = { 
        {'a', 2,  60},
        {'b', 1, 100},
        {'c', 3,  20},
        {'d', 2,  40},
        {'e', 1,  20},
   };
   int n = sizeof(arr) / sizeof(arr[0]);
   qsort(arr, n, sizeof(Jobs), compare);
   printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(int i = 0; i< n; i++) {
        printf("%10c %10i %10i\n", arr[i].id, arr[i].dead, arr[i].profit);
    }
   int result[n];
   bool slot[n];
    int maxProfit = 0;
   for (int i = 0; i < n; i++)
      slot[i] = false;
   for (int i = 0; i < n; i++) {
      for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
         if (slot[j] == false) {
            result[j] = i;
            maxProfit += arr[i].profit;
            slot[j] = true;
            break;
         }
      }
   }
   printf("Following is maximum profit sequence of Jobs: ");
   for (int i = 0; i < n; i++)
      if (slot[i]){
        printf("%c ", arr[result[i]].id);
      }

    printf("\nMaximum Profit : %d",maxProfit);
   return 0;
}
