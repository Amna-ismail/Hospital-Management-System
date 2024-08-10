// aqsa pf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "welcome to hospital" << endl;
	int option;
	char keepUsing='y';
	int id = 0, r = 0, w = 0, password = 0;
	
		struct patient_info
		{
			int  id_no;
			char name[10];
			int age;
			char gender[10];
			char phone_no[12];
			char disease[15];
			char medicine[14];
			char address[14];
			int room_no;
			int ward_no;
		};
		struct room_info
		{
			int  room_no;
			int no_of_beds;
			bool ac;
			bool attached_bathroom;
			bool phone;

			int occupied_bed;

		};
		patient_info p1[50] = { { 1, "aqsa", 18, "female", "0345978705", "malaria", "rizek", "Rawalpindi", 3, 4 },
		{ 2, "amna", 18, "female", "03459798705", "diabities", "rizek", "Rawalpindi", 2, 4 },
		{ 3, "ayesha", 18, "female", "03459798705", "cancer", "rizek", "Rawalpindi", 1, 4 },
		{ 4, "sadia", 18, "female", "03459798705", "bp", "co-easy", "Rawalpindi", 3, 2 },
		{ 5, "huma", 18, "female", "03459798705", "malaria", "rizek", "Rawalpindi", 4, 3 },
		};



		room_info r1[10] = { { 1, 2, true, false, true, 1 },
		{ 2, 3, true, true, true, 3 },
		{ 3, 2, true, false, true, 2 },
		{ 4, 4, false, true, true, 2 },
		{ 5, 3, true, false, true, 3 },
		{ 6, 2, false, false, true, 1 },
		};
		struct ward_info
		{
			int  ward_no;
			int no_of_beds;
			bool ac;
			int occupied_bed;
		};
		ward_info w1[10] = { { 1, 4, true, 3 },
		{ 2, 3, true, 2 },
		{ 3, 4, true, 2 },
		{ 4, 4, true, 4 },
		{ 5, 0, true, 0 },
		};

		do
		{
			cout << "1.want to see pateint information using patient id" << endl;
			cout << "2.information about the room no:" << endl;
			cout << "3. information about ward number" << endl;
			cout << "4. add record" << endl;
			cout << "5. delete record" << endl;
			cout << "6. update patient id,room no or ward number" << endl;
			cout << "select any option from above: \n";
			cin >> option;
			bool matchFound = 0;
		if (option == 1)
		{
			cout << "enter patient id:" << endl;
			cin >> id;
			
			for each(patient_info p in p1)
			{
				if (p.id_no == id)
				{
					matchFound = 1;
					cout << "patient's details are: \n";
					cout << "name: " << p.name << "\n";
					cout << "age: " << p.age << "\n";
					cout << "address: " << p.address << "\n";
					cout << "disease: " << p.disease << "\n";
					cout << "gender: " << p.gender << "\n";
					cout << "medicine: " << p.medicine << "\n";
					cout << "phone_no: " << p.phone_no << "\n";
					cout << "room_no: " << p.room_no << "\n";
					cout << "ward_no: " << p.ward_no << "\n";
				}
				
			}
			if (matchFound==0)
				cout << "no such pateint exist ";
				
		}
		else if (option == 2)
		{
			cout << "enter room number:" << endl;
			cin >> r;
			
			for each(room_info room in r1)
			{
				if (room.room_no == r)
				{
					matchFound = 1; 
					cout << "Room details are: \n";
					cout << "no_of_beds: " << room.no_of_beds << "\n";
					cout << "AC available: " << room.ac << "\n";
					cout << "Attached bathroom: " << room.attached_bathroom << "\n";
					cout << "Phone available: " << room.phone << "\n";
					cout << "occupied beds " << room.occupied_bed << "\n";
				}
				
			}
			if (matchFound == 0)
				cout << "no such room exist ";

		}


		else if (option == 3)
		{
			
			cout << "enter ward number:" << endl;
			cin >> w;
			for each(ward_info ward in w1)
			{
				if (ward.ward_no == w)
				{
					matchFound = 1;
					cout << "ward details are: \n";
					cout << "no_of_beds: " << ward.no_of_beds << "\n";
					cout << "AC available: " << ward.ac << "\n";
					cout << "occupied beds " << ward.occupied_bed << "\n";

				}
				else cout << "no such ward exist";
			}
			if (matchFound == 0)
				cout << "no such ward exist ";
		}
		else if (option == 4)
		{
			cout << "enter password if you are admin" << endl;
			cin >> password;
			int index = 0;


			if (password == 0)
			{
				for each(patient_info pt in p1)
				{
					if (strlen(pt.name)!=0)
					index++;
				}
				cout << "Please enter the patient details \n";
				p1[index + 1].id_no = index + 1;
				cout << "enter name: ";
				cin >> p1[index + 1].name;
				cout << "enter age: ";
				cin >> p1[index + 1].age;
				cout << "enter gender: ";
				cin >> p1[index + 1].gender;
				cout << "enter phone no: ";
				cin >> p1[index + 1].phone_no;
				cout << "enter disease: ";
				cin >> p1[index + 1].disease;
				cout << "enter address: ";
				cin >> p1[index + 1].address;
				cout << "enter room no: ";
				cin >> p1[index + 1].room_no;
				cout << " enter ward no: ";
				cin >> p1[index + 1].ward_no;


				/*char ch;
				cout << "do you want a room(y/n)";
				cin >> ch;
				if (ch == 'y')
				{
					cout << "enter room number:" << endl;
					cin >> r;
				}
				for each(room_info room in r1)
				{
					if (room.room_no == r)
					{
						cout << "Room details are: \n";
						cout << "no_of_beds: " << room.no_of_beds << "\n";
						cout << "AC available: " << room.ac << "\n";
						cout << "Attached bathroom: " << room.attached_bathroom << "\n";
						cout << "Phone available: " << room.phone << "\n";
						cout << "occupied beds " << room.occupied_bed << "\n";

					}
					if (room.occupied_bed < room.no_of_beds)
					{
						int available_bed;
						available_bed = room.no_of_beds - room.occupied_bed;

						cout << "available bed =" << available_bed;

					}

					else cout << "go to another room";
				}*/

			}
			else cout << "password is incorrect";
		}
		else if (option == 5)
		{
			cout << "enter patient id to delete the record:" << endl;
			cin >> id;
			matchFound = 0;
			int size = 50;
			for (int i = 0; i<size; i++)
			{
				if (p1[i].id_no == id)
				{
					matchFound = 1;
					p1[i].id_no = p1[i+1].id_no;
					strcpy_s(p1[i].address, p1[i + 1].address);
					p1[i].age = p1[i + 1].age;
					strcpy_s(p1[i].gender, p1[i + 1].gender);
					strcpy_s(p1[i].medicine, p1[i + 1].medicine);
					strcpy_s(p1[i].name, p1[i + 1].name);
					strcpy_s(p1[i].phone_no, p1[i + 1].phone_no);
					p1[i].room_no = p1[i + 1].room_no;
					p1[i].ward_no = p1[i + 1].ward_no;
				}
				size--;
			}
			if (matchFound == 0)
				cout << "no such pateint exist ";

		}
		else if (option == 6)
		{
			cout << "enter patient id to update the record:" << endl;
			cin >> id;
			matchFound = 0;
			int ward_no, room_no;
			cout << "Enter new ward no.";
			cin >> ward_no;
			cout << "Enter new room no.";
			cin >> room_no;
			int size = 50;
			for (int i = 0; i<size; i++)
			{
				if (p1[i].id_no == id)
				{
					matchFound = 1;
					p1[i].id_no = p1[i].id_no;
					strcpy_s(p1[i].address, p1[i].address);
					p1[i].age = p1[i].age;
					strcpy_s(p1[i].gender, p1[i].gender);
					strcpy_s(p1[i].medicine, p1[i].medicine);
					strcpy_s(p1[i].name, p1[i].name);
					strcpy_s(p1[i].phone_no, p1[i].phone_no);
					p1[i].room_no =room_no;
					p1[i].ward_no =ward_no;
				}
				size--;
			}
			if (matchFound == 0)
				cout << "no such pateint exist ";

		}
		cout << "do you want to continue?(y/n)";
		cin >> keepUsing;
	}
	while (keepUsing == 'y');

		system("pause");
		return 0;
	}                                    








































































































