#include<iostream>
using namespace std;

// Damage Score :
const int DAMAGE_LOW_SCORE = 10;
const int DAMAGE_MEDIUM_SCORE = 20;
const int DAMAGE_HIGH_SCORE = 30;

// Family Affected Score :
const int FAMILY_AFFECTED_1_TO_10_SCORE = 10;
const int FAMILY_AFFECTED_11_to_50_SCORE = 15;
const int FAMILY_AFFECTED_51_TO_100_SCORE = 20;
const int FAMILY_AFFECTED_101_TO_150_SCORE = 25;
const int FAMILY_AFFECTED_151_TO_200_SCORE = 30;
const int FAMILY_AFFECTED_GREATER_THAN_200_SCORE = 35;

//Routes Score
const int ROUTES_OPENED_SCORE = 5;
const int ROUTES_DAMAGED_SCORE = -5;

//Flood Warning Score :
const int FLOOD_WARNING_YES_SCORE = 10;
const int FLOOD_WARNING_NO_SCORE = 0;

//Medical Need Score :
const int MEDICAL_NEED_YES_SCORE = 15;
const int MEDICAL_NEED_NO_SCORE = 0;

//Previous Score :
const int PREVIOUS_HELP_AVAILED_SCORE = -5;
const int PREVIOUS_HELP_NOT_AVAILED_SCORE = 5;

// Counter
int completedRequestsCount = 0;
int defferedRequestsCount = 0;
int notServedRequestsCount = 0;
int totalRequestsCount = 0;

//User Inputs
int userDamageScore;
int userFamilyAffectedScore;
int userRoutesScore;
int userFloodScore;
int userMedicalScore;
int userPreviousHelpScore;

int damage;
int familyAffected;
int routes;
int floodWarning;
int medicalNeed;
int previousHelp;

//Aid
int score;
int totalTrucks = 5;
int totalSupplyPacks = 120;


int trucksUsed;
int packsUsed;

int choice;


int main() {

	while (true) {
		// Question :
		cout << "Hello! To enter your emergency request , Please select the damage level (1,2,3) ";
		cout << endl << "1. Low \n2. Medium\n3. High\n";
		cin >> damage;

		// This if block is used to deal with char / string error in input
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}


		switch (damage) {

		case 1:
			userDamageScore = DAMAGE_LOW_SCORE;
			break;
		case 2:
			userDamageScore = DAMAGE_MEDIUM_SCORE;
			break;
		case 3:
			userDamageScore = DAMAGE_HIGH_SCORE;
			break;
		default:
			cout << "Invalid Damage Level\n";
			continue;
		}

		//Question :
		cout << "Okay . To process your request , Please tell how many families have been affected in your area.\n";
		cin >> familyAffected;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}


		if (familyAffected <= 0) {
			userFamilyAffectedScore = 0;
		}

		else if (familyAffected >= 1 && familyAffected <= 10) {
			userFamilyAffectedScore = FAMILY_AFFECTED_1_TO_10_SCORE;
		}

		else if (familyAffected >= 11 && familyAffected <= 50) {
			userFamilyAffectedScore = FAMILY_AFFECTED_11_to_50_SCORE;
		}

		else if (familyAffected >= 51 && familyAffected <= 100) {
			userFamilyAffectedScore = FAMILY_AFFECTED_51_TO_100_SCORE;
		}

		else if (familyAffected >= 101 && familyAffected <= 150) {
			userFamilyAffectedScore = FAMILY_AFFECTED_101_TO_150_SCORE;
		}

		else if (familyAffected >= 151 && familyAffected <= 200) {
			userFamilyAffectedScore = FAMILY_AFFECTED_151_TO_200_SCORE;
		}

		else {
			userFamilyAffectedScore = FAMILY_AFFECTED_GREATER_THAN_200_SCORE;
		}


		//Question :
		cout << "Is the access route open? (1 = Open, 2 = Damaged)\n";
		cin >> routes;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}

		if (routes == 1) {
			userRoutesScore = ROUTES_OPENED_SCORE;
		}
		else {
			userRoutesScore = ROUTES_DAMAGED_SCORE;
		}

		//Question:
		cout << "Is there a flood warning? (1 = Yes, 0 = No)\n";
		cin >> floodWarning;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}

		if (floodWarning == 1) {
			userFloodScore = FLOOD_WARNING_YES_SCORE;
		}
		else {
			userFloodScore = FLOOD_WARNING_NO_SCORE;
		}

		//Question :
		cout << "Is there any medical need? (1 = Yes, 0 = No)\n";
		cin >> medicalNeed;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}

		if (medicalNeed == 1) {
			userMedicalScore = MEDICAL_NEED_YES_SCORE;
		}
		else {
			userMedicalScore = MEDICAL_NEED_NO_SCORE;
		}


		cout << "Was previous aid received? (1 = Yes, 0 = No)\n";
		cin >> previousHelp;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please enter numbers only.\n";
			continue;
		}

		if (previousHelp == 1) {
			userPreviousHelpScore = PREVIOUS_HELP_AVAILED_SCORE;
		}
		else {
			userPreviousHelpScore = PREVIOUS_HELP_NOT_AVAILED_SCORE;
		}


		score = userDamageScore + userFamilyAffectedScore + userRoutesScore + userFloodScore + userMedicalScore + userPreviousHelpScore;

		totalRequestsCount++;
		trucksUsed = 0;
		packsUsed = 0;

		cout << "\nNeed Score = " << score << endl;


		//  Full Relief (2 trucks, 50 packs)
		if (score >= 65) {

			if (totalTrucks >= 2 && totalSupplyPacks >= 50) {

				trucksUsed = 2;
				packsUsed = 50;
				cout << "Action A : Full Relief is on the way to your location.\n";
				completedRequestsCount++;
			}

			else if (totalTrucks >= 1 && totalSupplyPacks >= 30) {

				trucksUsed = 1;
				packsUsed = 30;
				cout << "Full Relief not available at the moment.\n";
				cout << "Action B : Standard Relief is on the way to your location.\n";
				completedRequestsCount++;
			}

			else if (totalTrucks >= 1 && totalSupplyPacks >= 10) {

				trucksUsed = 1;
				packsUsed = 10;
				cout << "Full Relief not available at the moment.\n";
				cout << "Action C : Emergency Kit Only is on the way to your location.\n";
				completedRequestsCount++;
			}

			else {
				cout << "We are Sorry. We are out of resources at the moment.\n";
				cout << "Request Not Served.\n";
				notServedRequestsCount++;
			}
		}

		//  Standard Relief (1 truck, 30 packs)
		else if (score >= 45) {

			if (totalTrucks >= 1 && totalSupplyPacks >= 30) {

				trucksUsed = 1;
				packsUsed = 30;
				cout << "Action B : Standard Relief is on the way to your location.\n";
				completedRequestsCount++;
			}

			else if (totalTrucks >= 1 && totalSupplyPacks >= 10) {

				trucksUsed = 1;
				packsUsed = 10;
				cout << "Standard Relief not available at the moment.\n";
				cout << "Action C : Emergency Kit Only is on the way to your location.\n";
				completedRequestsCount++;
			}

			else {
				cout << "We are Sorry. We are out of resources at the moment.\n";
				cout << "Request Not Served.\n";
				notServedRequestsCount++;
			}
		}

		//  Emergency Kit Only (1 truck, 10 packs)
		else if (score >= 25) {

			if (totalTrucks >= 1 && totalSupplyPacks >= 10) {

				trucksUsed = 1;
				packsUsed = 10;
				cout << "Action C : Emergency Kit Only is on the way to your location.\n";
				completedRequestsCount++;
			}

			else {
				cout << "We are Sorry. We are out of resources at the moment.\n";
				cout << "Request Not Served.\n";
				notServedRequestsCount++;
			}
		}

		// Score less than 25 : Defer / Monitor (0 trucks, 0 packs)
		else {

			cout << "Action D : Defer / Monitor. Your request will be monitored.\n";
			defferedRequestsCount++;
		}


		totalTrucks = totalTrucks - trucksUsed;
		totalSupplyPacks = totalSupplyPacks - packsUsed;

		cout << "Trucks used = " << trucksUsed << " , Supply Packs used = " << packsUsed << endl;
		cout << "Remaining Trucks = " << totalTrucks << " , Remaining Supply Packs = " << totalSupplyPacks << endl;


		cout << "\nDo you want to enter another request? (1 = Yes, 0 = No)\n";
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Program will end.\n";
			choice = 0;
		}

		if (choice != 1) {
			break;
		}
	}

	// Final Output
	cout << "\n------ FINAL SUMMARY ------\n";
	cout << "Total Requests = " << totalRequestsCount << endl;
	cout << "Successfully Served = " << completedRequestsCount << endl;
	cout << "Deferred / Monitored = " << defferedRequestsCount << endl;
	cout << "Not Served = " << notServedRequestsCount << endl;
	cout << "Remaining Trucks = " << totalTrucks << endl;
	cout << "Remaining Supply Packs = " << totalSupplyPacks << endl;

	return 0;
}
