/*
At the ticket counter of football stadium, people come
in queue and purchase tickets. Arrival rate of customers
is 1/min. It takes at the average 20 seconds to purchase
the ticket.
WAP in C to calculate total time spent by a sports
fan to be seated in his seat, if it takes 1.5 minutes to
reach the correct seat after purchasing the ticket.
if a fan comes exactly before 2 minutes before the
game starts, can sports fan expects to be seated for the
kick-off?
*/
#include <stdio.h>

int main() {
    float arrival_rate = 1.0;    // Customers per minute
    float service_rate = 3.0;   // Customers per minute (since 20 sec = 3/min)
    float travel_time = 1.5;    // Time to reach the seat (in minutes)
    float time_before_game = 2.0; // Time before game starts (in minutes)

    
    float utilization = arrival_rate / service_rate;

    
    if (utilization >= 1) {
        printf("The system is unstable. Arrival rate exceeds service rate.\n");
        return 0;
    }

    
    float time_in_system = 1 / (service_rate - arrival_rate);

    
    float total_time = time_in_system + travel_time;

   
    printf("Expected time spent in the system (queue + service): %.2f minutes\n", time_in_system);
    printf("Total time spent by the fan (system + travel): %.2f minutes\n", total_time);

    
    if (total_time <= time_before_game) {
        printf("The fan can be seated before the kickoff.\n");
    } else {
        printf("The fan cannot be seated before the kickoff.\n");
    }

    return 0;
}
