#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{ 
	double data;
	int n = 0;
	cout << sizeof(data) << endl;

	ifstream fin("data.dat", ios_base::binary);
	ofstream fout("dataout.dat", ios_base::binary | ios_base::app);

	if (fin.is_open() && fout.is_open())
	{
		while (1)
		{
			fin.read((char*)&data, sizeof(data));
			if (fin.eof())
			{
				break;
			}
			else
			{
				cout << data << ' ';
				fout.write((char*)&data, sizeof(data));

				n++;
			}
		}
		cout << endl;
		cout << " number of data in the file:" << n << endl;
		fin.close();
		fout.close();
	}

	return 0;
}