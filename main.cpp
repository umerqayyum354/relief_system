#include<iostream>
using namespace std;

const int FLOOD_SCORE = 30;
const int EARTHQUAKE_SCORE = 15;
const int HEATWAVE_SCORE = 15;
const int FIRE_SCORE = 10;
const int BRIDGEDOWN_SCORE = 10;


const int FAMILY_AFFECTED_1_TO_10_SCORE = 10;
const int FAMILY_AFFECTED_11_to_50_SCORE = 15;
const int FAMILY_AFFECTED_51_TO_100_SCORE = 20;
const int FAMILY_AFFECTED_101_TO_150_SCORE = 25;
const int FAMILY_AFFECTED_151_TO_200_SCORE = 30;
const int FAMILY_AFFECTED_GREATER_THAN_200_SCORE = 35;

const int PREVIOUS_HELP_AVAILED_SCORE = -5;
const int PREVIOUS_HELP_NOT_AVAILED_SCORE = 5;

const int ROUTES_OPENED_SCORE = 5;
const int ROUTES_CLOSED_SCORE = -5;



int userIncidentScore;
int userFamilyAffectedScore;
int userPreviousHelpScore;
int userRoutesScore;

int familyAffected;
int incident;

int score;
int totalTrucks = 5;
int totalSupplyPacks = 120;
int EmergKits = 100;


int main() {

	while (true) {

		cout << "Hello! To enter your emergency request , Please select the incident number from the given options(1,2,3,4,5) ";
		cout << endl << "1. Flood \n2.Earthquake\n3.Fire\n4.Heat-Wave\n5.Bridge Down";
		cin >> incident;

		switch (incident) {

			case 1:
				userIncidentScore = FLOOD_SCORE;
				break;
			case 2:
				userIncidentScore = EARTHQUAKE_SCORE;
				break;
			case 3:
				userIncidentScore = FIRE_SCORE;
				break;
			case 4:
				userIncidentScore = HEATWAVE_SCORE;
				break;
			case 5:
				userIncidentScore = BRIDGEDOWN_SCORE;
				break;
			default:
				cout << "Invalid Incident";
				continue;
		}

		cout << "Okay . To process your request , PLease tell how many families ;have been affected in your area.";
		cin >> familyAffected;


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



		cout << "Any Previous help provided?";
		cin >> userPreviousHelpScore;

		if (userPreviousHelpScore == 1) {
			userPreviousHelpScore = PREVIOUS_HELP_AVAILED_SCORE;
		}
		else {
			userPreviousHelpScore = PREVIOUS_HELP_NOT_AVAILED_SCORE;
		}


		cout << "Are routes working?";
		cin >> userRoutesScore;

		if (userRoutesScore == 1) {
			userRoutesScore = ROUTES_OPENED_SCORE;
		}
		else {
			userRoutesScore = ROUTES_CLOSED_SCORE;
		}


		score = userIncidentScore + userFamilyAffectedScore + userPreviousHelpScore + userRoutesScore;


		// Damage Level High
		if (score >= 50) {

			if (totalTrucks >= 3 && totalSupplyPacks >= 30) {

				totalTrucks = totalTrucks - 3;
				totalSupplyPacks = totalSupplyPacks - 30;

				cout << "Damage Level High \n << High Relief is on the way to your location \n 3 Trucks and 30 Supply Packs are sent.";
			}

			else if (totalTrucks < 3 || totalSupplyPacks < 30) {

				totalTrucks = totalTrucks - 1;
				totalSupplyPacks = totalSupplyPacks - 5;
				EmergKits = EmergKits - 20;

				cout << "Damage Level High \n << High Relief Not available at the moment << 1 truck , 5 Supply Packs and 20 Emergency Kits are sent";
			}

			else if (totalTrucks == 0 || totalSupplyPacks == 0) {

				 if (EmergKits < 10) {
					cout << "We are Sorry.We are out of resources at the moment";
				 }

				 else if (EmergKits >= 30) {
					EmergKits = EmergKits - 30;
					cout << "We are Sorry . We are out of resources at the moment";
					cout << "30 Emergency Kits are sent to help at this moment";
				 }
				
				else if (EmergKits < 30) {

					EmergKits = EmergKits - 10;

					cout << "We are Sorry.We are out of resources at the moment";
					cout << "10 Emergency Kits are sent to help at this moment";
				}
			}
		}

		else if (score > 25) {

			if (totalTrucks >= 2 && totalSupplyPacks >= 10) {

				totalTrucks = totalTrucks - 2;
				totalSupplyPacks = totalSupplyPacks - 10;

				cout << "Damage Level Medium \n << Standard Relief is on the way to your location \n 2 Trucks and 10 Supply Packs are sent.";
			}

			else if (totalTrucks < 2 || totalSupplyPacks < 10) {

				totalTrucks = totalTrucks - 1;
				totalSupplyPacks = totalSupplyPacks - 5;
				EmergKits = EmergKits - 20;

				cout << "Damage Level High \n << High Relief Not available at the moment << 1 truck , 5 Supply Packs and 20 Emergency Kits are sent";
			}

			else if (totalTrucks == 0 || totalSupplyPacks == 0) {
				if (EmergKits < 10) {

					cout << "We are Sorry.We are out of resources at the moment";

				}

				else if (EmergKits >= 20) {
					EmergKits = EmergKits - 20;
					cout << "We are Sorry . We are out of resources at the moment";
					cout << "20 Emergency Kits are sent to help at this moment";
				}

				else if (EmergKits < 20) {

					EmergKits = EmergKits - 10;

					cout << "We are Sorry.We are out of resources at the moment";
					cout << "10 Emergency Kits are sent to help at this moment";
				}
			}
		}

		else if (score < 25) {

			if (totalTrucks >= 1 && totalSupplyPacks >= 5) {

				totalTrucks = totalTrucks - 1;
				totalSupplyPacks = totalSupplyPacks - 5;

				cout << "Damage Level Low \n << Low Relief is on the way to your location \n 1 Trucks and 5 Supply Packs are sent.";
			}

			else if (totalTrucks < 1 || (totalSupplyPacks < 5 && totalSupplyPacks >= 3)) {

				totalSupplyPacks = totalSupplyPacks - 3;


				if (EmergKits >= 10) {
					EmergKits = EmergKits - 10;

					cout << "Damage Level Low \n << Low Relief Not available at the moment <<  3 Supply Packs and 10 Emergency Kits are sent";
				}

				else if (EmergKits >= 5) {

					cout << "Damage Level Low \n << Low Relief Not available at the moment <<  3 Supply Packs and 5 Emergency Kits are sent.";
				}
				else {
					cout << "Damage Level Low \n << Low Relief Not available at the moment ";
				}
			}

			else if (totalTrucks == 0 || totalSupplyPacks == 0) {

				if (EmergKits >= 10) {
					EmergKits = EmergKits - 10;
					cout << "We are Sorry . We are out of resources at the moment";
					cout << "10 Emergency Kits are sent to help at this moment";
				}
				else if (EmergKits < 10) {

					EmergKits = EmergKits - 5;

					cout << "We are Sorry.We are out of resources at the moment";
					cout << "5 Emergency Kits are sent to help at this moment";
				}
				else if (EmergKits < 5) {

					cout << "We are Sorry.We are out of resources at the moment";

				}
			}
		}

		else if (score < 10) {

			if (EmergKits >= 10) {
				EmergKits = EmergKits - 10;
				cout << "We are Sorry . We are out of resources at the moment";
				cout << "10 Emergency Kits are sent to help at this moment";
			}
			else if (EmergKits < 10) {

				EmergKits = EmergKits - 5;

				cout << "We are Sorry.We are out of resources at the moment";
				cout << "5 Emergency Kits are sent to help at this moment";
			}
			else if (EmergKits < 5) {
				cout << "We are Sorry.We are out of resources at the moment";

			}
		}
	}
}

	








