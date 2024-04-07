#include <stdio.h>
#include <stdbool.h>

// Function to find the index of the page that will not be used for the longest time in the future
int findOptimalIndex(int page_requests[], int num_requests, int frames[], int num_frames, int index) {
    int res = -1, farthest = index;
    int i;
    for ( i = 0; i < num_frames; i++) {
        int j;
        for (j = index; j < num_requests; j++) {
            if (frames[i] == page_requests[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If the page is not found in future requests, it's the optimal page for replacement
        if (j == num_requests)
            return i;
    }
    return (res == -1) ? 0 : res;
}

// Function to simulate the Optimal page replacement algorithm
int optimal(int page_requests[], int num_requests, int frame_size) {
    int page_faults = 0;
    int frames[frame_size];
    bool page_present[frame_size];
	int i,j;
    // Initialize frames with -1 indicating an empty frame
    for (i = 0; i < frame_size; i++) {
        frames[i] = -1;
        page_present[i] = false;
    }

    // Iterate over each page request
    for (i = 0; i < num_requests; i++) {
        int page = page_requests[i];
        int found = 0;

        // Check if the page is already present in any of the frames
        for (j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // If the page is not found in any frame, it's a page fault
        if (!found) {
            page_faults++;
            // Find the index of the page that will not be used for the longest time in the future
            int index = findOptimalIndex(page_requests, num_requests, frames, frame_size, i + 1);
            frames[index] = page; // Replace the optimal page
        }
    }

    return page_faults; // Return the total number of page faults
}

int main() {
    int frame_size, num_requests;
	int i;
    // Asking the user to input the frame size
    printf("Enter the frame size: ");
    scanf("%d", &frame_size);

    // Asking the user to input the number of page requests
    printf("Enter the number of page requests: ");
    scanf("%d", &num_requests);

    int page_requests[num_requests];

    // Asking the user to input each page request individually
    printf("Enter the page requests:\n");
    for (i = 0; i < num_requests; i++) {
        scanf("%d", &page_requests[i]);
    }

    // Calling the optimal function and printing the total number of page faults
    printf("Total page faults using Optimal: %d\n", optimal(page_requests, num_requests, frame_size));

    return 0;
}

