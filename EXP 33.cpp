#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3

// Function to print the current state of frames
void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int frames[MAX_FRAMES];
    
    // Initialize frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    int pageFaults = 0;
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    
    // Print reference string
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n\n");

    printf("Page Replacement Order:\n");

    // Iterate through the reference string
    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in memory (a page hit)
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page not found (page fault)
        if (!pageFound) {
            printf("Page %d -> ", page);

            int optimalPage = -1;
            int farthestDistance = 0;

            // Find the optimal page to replace
            for (int j = 0; j < MAX_FRAMES; j++) {
                int futureDistance = 0;

                // Check when the page will be used next
                for (int k = i + 1; k < n; k++) {
                    if (referenceString[k] == frames[j]) {
                        break;
                    }
                    futureDistance++;
                }

                // Find the page that is farthest in the future or not used again
                if (futureDistance > farthestDistance) {
                    farthestDistance = futureDistance;
                    optimalPage = j;
                }
            }

            // Replace the optimal page
            frames[optimalPage] = page;
            printFrames(frames, MAX_FRAMES);
            pageFaults++;
        }
    }

    // Output the total number of page faults
    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
