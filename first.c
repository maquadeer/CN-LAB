#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    
    while (1) {
        printf("Select an option:\n");
        printf("1. Run tcpdump\n");
        printf("2. Run netstat\n");
        printf("3. Run ifconfig\n");
        printf("4. Run nslookup\n");
        printf("5. Run FTP\n");
        printf("6. Run TELNET\n");
        printf("7. Run traceroute\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                system("tcpdump -i eth0"); // Replace 'eth0' with your network interface
                break;
            case 2:
                system("netstat -tuln");
                break;
            case 3:
                system("ifconfig");
                break;
            case 4:
                printf("Enter the hostname to look up: ");
                char hostname[256];
                scanf("%s", hostname);
                char nslookupCommand[256];
                sprintf(nslookupCommand, "nslookup %s", hostname);
                system(nslookupCommand);
                break;
            case 5:
                system("ftp"); // This will start an interactive FTP session
                break;
            case 6:
                system("telnet"); // This will start an interactive TELNET session
                break;
            case 7:
                printf("Enter the destination IP or hostname for traceroute: ");
                char dest[256];
                scanf("%s", dest);
                char tracerouteCommand[256];
                sprintf(tracerouteCommand, "traceroute %s", dest);
                system(tracerouteCommand);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

