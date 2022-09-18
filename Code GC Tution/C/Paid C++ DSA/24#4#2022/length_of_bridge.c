#include <stdio.h>

int main(int argc, char const *argv[])
{
    int train_length, speed, time;
    printf("Enter the length of the train: ");
    scanf("%d", &train_length);
    printf("Enter the speed of the train: ");
    scanf("%d", &speed);
    printf("Enter the time of crossing the bridge: ");
    scanf("%d", &time);

    int length_of_bridge = (speed * time) - train_length;
    printf("The length of the bridge is: %d", length_of_bridge);
    return 0;
}
