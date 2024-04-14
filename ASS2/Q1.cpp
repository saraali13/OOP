#include <iostream>
#include <string>
using namespace std;


// security tool class
class SecurityTool 
{
protected:
	
    string securityLevel;
    double toolCost;
    int Devices;

public:
	
    // Parameterized constructor
    SecurityTool(string securityLevel, double toolCost, int Devices) : securityLevel(securityLevel), toolCost(toolCost), Devices(Devices) 
	{
        if (securityLevel != "High" && securityLevel != "Medium" && securityLevel != "Low") 
		{
            cout << "Invalid security level...Security level setted as low\n";
            securityLevel = "Low";
        }
        if (toolCost <= 0) 
		{
            cout << "Invalid cost...Cost setted as 1\n";
            toolCost = 1;
        }
    }

    // Function for scaning
    void performScan() 
	{
        cout << "Performing a generic security scan..." << endl;
    }
};//end security tool class


// fire wall tool class inherhits security tool class
class FireWallTool : public SecurityTool 
{
private:

    int* ports;
    string* protocols;

public:

    // Parameterized constructor
    FireWallTool(string securityLevel, double toolCost, int Devices, int* Ports, string* Protocols)
        : SecurityTool(securityLevel, toolCost, Devices) 
		{
        ports = new int[24];//DMA for ports
        for (int i = 0; i < 24; ++i) 
		{
            ports[i] = Ports[i];
        }
        protocols = new string[6];//DMA for protocols
        for (int i = 0; i < 6; ++i) 
		{
            protocols[i] = Protocols[i];
        }

        if (Devices > 10) 
		{
            cout << "Number of devices reached its limit...Number of devices setted as 10\n";
            Devices = 10;
        }
    }

    // Destructor 
    ~FireWallTool() 
	{
        delete[] ports;
        delete[] protocols;
    }

    // Function for generating port list
    void generateList(int Port) 
	{
        for (int i = 0; i < 24; ++i) {
            ports[i] = Port + i;
        }
    }

    // Function to perform a firewall scan
    void performScan() 
	{
        cout << "Performing a firewall scan:\n";
        cout << "Security Level: " << securityLevel;
        cout << "\nCost: " << toolCost;
        cout << "\nNumber of Devices: " << Devices << endl;

        if (securityLevel == "High") 
		{
            cout << "Allowing traffic only from port list and protocol list\n";
        } 
		else if (securityLevel == "Medium") 
		{
            cout << "Allowing traffic from port list, protocol list, and next two ports in sequence\n" ;
            for (int i = 0; i < 2; ++i) {
                cout << ports[23] + i + 1 << " ";
            }
            cout << endl;
        } 
		else 
		{
            cout << "Allowing traffic from port list, protocol list, and next five ports in sequence, TCP, and DNS protocol\n";
            for (int i = 0; i < 5; ++i) 
			{
                cout << ports[23] + i + 1 << " ";
            }
            cout << "TCP DNS\n";
        }
    }
};//end firewall class

int main() 
{
   cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    int Ports[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    string Protocols[] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
    FireWallTool firewall("Medium", 200, 9, Ports, Protocols);

    firewall.generateList(5);
    firewall.performScan();

    return 0;
}//end main
