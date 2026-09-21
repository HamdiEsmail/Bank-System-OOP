#pragma once
#include "clsScreen.h"
#include"../../clsBankClient.h"
#include<iomanip>
class clsTransferLogScreen :
	protected clsScreen
{
private:
	static void _PrintTransLogRecord(clsBankClient::stTransferLog TransLog) {

		cout << setw(10) << left << ""
			<< "| " << setw(25) << left << TransLog.DateTime << "| "
			<< setw(10) << left << TransLog.SAccNumber << "| "
			<< setw(10) << left << TransLog.DAccNumber << "| "
			<< setw(10) << left << TransLog.Amount << "| "
			<< setw(13) << left << TransLog.SBalance << "| "
			<< setw(13) << left << TransLog.DBalance << "| "
			<< setw(13) << left << TransLog.CurrUser << endl;




	}

public:
	static void ShowTransformListScreen() {
		vector<clsBankClient::stTransferLog>vAllTransLog = clsBankClient::GetAllTransferLogs();
		string Title = "Transfer Log List Screen";
		string SubTitle = "(" + to_string(vAllTransLog.size()) + ") Record(s)";
		DrawHeaderScreen(Title, SubTitle);
		cout << setw(10) << "" << "____________________________________________________________________________________________________________\n";
		cout << setw(10) << left << ""
			<< "| " << setw(25) << left << "Date/Time" << "| "
			<< setw(10) << left << "SAccNumber" << "| "
			<< setw(10) << left << "DAccNumber" << "| "
			<< setw(10) << left << "Amount" << "| "
			<< setw(13) << left << "SBalance" << "| "
			<< setw(13) << left << "DBalance" << "| "
			<< setw(13) << left << "CurrUser";
		cout << endl << setw(10) << "" << "____________________________________________________________________________________________________________\n";
		for (clsBankClient::stTransferLog& CurrTransLog : vAllTransLog) {

			_PrintTransLogRecord(CurrTransLog);


		}
		cout << endl << setw(10) << "" << "______________________________________________________________________________________________________________\n";



	}

};

