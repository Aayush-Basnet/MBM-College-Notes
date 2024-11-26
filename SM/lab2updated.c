/*
Customers arrive in a bank according to a Poisson's process
with mean inter arrival time of 10 minutes. Customers spend
an average of 5 minutes on the single available counter, and
leave.
Write a program in C to find:
I. Probability that a customer will not have to wait at
the counter.
II. Expected number of customers in the bank.
III. Time can a customer expect to spend in the bank.
*/
#include<stdio.h>

int main() {
    float inter_arrival_time, avg_service_time, lambda, mu, rho;
    float p_no_wait, expected_customers, expected_time;

    // Input: Inter-arrival time and service time
    printf("Enter inter-arrival time of customers (minutes): ");
    scanf("%f", &inter_arrival_time);
    printf("Enter average service time of customers (minutes): ");
    scanf("%f", &avg_service_time);

    // Calculate lambda and mu
    lambda = 60 / inter_arrival_time; // Convert inter-arrival time to customers/hour
    mu = 60 / avg_service_time;       // Convert service time to customers/hour

    // Check for stability condition (rho < 1)
    if (lambda >= mu) {
        printf("\nThe system is unstable (arrival rate exceeds service rate).\n");
        return 0;
    }

    // Utilization
    rho = lambda / mu;

   
    p_no_wait = 1 - rho;                                  
    expected_customers = lambda / (mu - lambda);          
    expected_time = (1 / (mu - lambda)) * 60;            

    // Output results
    printf("\nProbability that a customer will not have to wait at the counter: %.2f", p_no_wait);
    printf("\nExpected number of customers in the bank: %.2f", expected_customers);
    printf("\nExpected time a customer spends in the bank: %.2f minutes\n", expected_time);

    return 0;
}

