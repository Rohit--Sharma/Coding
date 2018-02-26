#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int n, p;
    int rfp_number = 1;
    scanf("%d %d\n", &n, &p);
    while (n != 0 && p != 0)
    {
        char best_proposal_name[85] = "Best Proposal";
        float max_compensation = -1.0;
        float min_price = 20000000.0;

        for (int i = 0; i < n; i++)
        {
            // string temp;
            // getline(cin, temp);
            char temp[85];
            //scanf("%[^\n]s", temp);
            //fgets(temp, 85, stdin);
            scanf("%[^\n]%*c", temp);
            //printf("RFP Name: %s\n", temp);
        }

        while (p--)
        {
            //string proposal_name;
            char proposal_name[85];
            int r;
            float d;

            //getline(cin, proposal_name);
            //fgets(proposal_name, 85, stdin);
            scanf("%[^\n]%*c", proposal_name);
            scanf("%f %d\n", &d, &r);

            for (int i = 0; i < r; i++)
            {
                // string temp;
                // getline(cin, temp);
                char temp[85];
                //scanf("%[^\n]s", temp);
                //fgets(temp, 85, stdin);
                scanf("%[^\n]%*c", temp);
                //printf("RFP Name: %s\n", temp);
            }

            float compensation = (float)r / n;
            //printf("ProposalName: %s, Compensation: %f, Price: %f\n", proposal_name, compensation, d);
            if (compensation > max_compensation)
            {
                max_compensation = compensation;
                strcpy(best_proposal_name, proposal_name);
            }
            if (compensation == max_compensation) {
                if (d < min_price) {
                    min_price = d;
                    strcpy(best_proposal_name, proposal_name);
                }
            }
        }

        if(rfp_number == 1)
            printf("RFP #%d\n%s\n", rfp_number++, best_proposal_name);
        else
            printf("\nRFP #%d\n%s\n", rfp_number++, best_proposal_name);
        scanf("%d %d\n", &n, &p);
    }

    return 0;
}