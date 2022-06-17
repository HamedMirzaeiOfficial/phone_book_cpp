#include <iostream>

using namespace std;

struct Contact
{
    string first_name;
    string last_name;
    string phone_number;
    int id;
};

int binary_search(int [], int, int, int);
void bubble_sort(Contact [], int);
void create_contact(Contact [], int);
void create_contact(Contact [], int);
void delete_contact(Contact [], int&);
void search_contact(Contact [], int);
void show_contacts(Contact [], int);
void sort_contacts(Contact [], int);
void menu();

int main()
{
    menu();
    return 0;
}

int search(Contact contacts[], int index, string x)
{
    for(int i=0; i<index; i++)
    {
        if (contacts[i].first_name == x || contacts[i].last_name == x)
            return i;
    }


    return -1;
}

void bubble_sort(Contact contacts[], int size)
{
    Contact temp;
    for(int i = 0; i < size - 1; i++)
    {

        for(int j = 0; j < size - i - 1; j++)
        {
            if (contacts[j].first_name > contacts[j + 1].first_name)
            {
                temp = contacts[j + 1];
                contacts[j + 1] = contacts[j];
                contacts[j] = temp;

            }
        }
    }


}

void create_contact(Contact contacts[], int index)
{
    cout<<"Enter a new contact firstname: ";
    cin>>contacts[index].first_name;
    cout<<"Enter a new contact lastname: ";
    cin>>contacts[index].last_name;
    cout<<"Enter a new contact number: ";
    cin>>contacts[index].phone_number;

    contacts[index].id = index;

}

void edit_contact(Contact contacts[], int index)
{
    string first_name, last_name;
    cout<<"Enter Contact firstname: ";
    cin>>first_name;
    cout<<"Enter Contact lastname: ";
    cin>>last_name;

    int found_index_1 =  search(contacts, index, first_name);
    int found_index_2 = search(contacts, index, last_name);

    if(found_index_1 != found_index_2)
    {
        cout<<"Not found!!!";
        exit(1);
    }

    cout<<"\n\nContact Info:";
    cout<<" id: "<<contacts[found_index_1].id<<"\n firstname: "<<contacts[found_index_1].first_name<<
        "\n lastname: "<<contacts[found_index_1].last_name<<"\n number: "<<contacts[found_index_1].phone_number<<"\n\n";

    cout<<"Enter new fistname: ";
    cin>>contacts[found_index_1].first_name;
    cout<<"Enter new lastname: ";
    cin>>contacts[found_index_1].last_name;
    cout<<"Enter new number: ";
    cin>>contacts[found_index_1].phone_number;

}

void delete_contact(Contact contacts[], int &index)
{
    char choice;
    string first_name, last_name;
    cout<<"Enter Contact firstname: ";
    cin>>first_name;
    cout<<"Enter Contact lastname: ";
    cin>>last_name;

    int found_index_1 =  search(contacts, index, first_name);
    int found_index_2 = search(contacts, index, last_name);

    if(found_index_1 != found_index_2)
    {
        cout<<"Not found!!!";
        exit(1);
    }

    cout<<"\n\nContact Info:";
    cout<<" id: "<<contacts[found_index_1].id<<"\n firstname: "<<contacts[found_index_1].first_name<<
        "\n lastname: "<<contacts[found_index_1].last_name<<"\n number: "<<contacts[found_index_1].phone_number<<"\n\n";

    cout<<"Are you sure delete contact(Y-N)? ";
    cin>>choice;
    if(choice == 'N')
        exit(0);

    int i;
    for (i=0; i<index; i++)
        if (contacts[i].first_name == first_name || contacts[i].last_name == last_name)
            break;

    if (i < index)
    {
        index = index - 1;
        for (int j=i; j<index; j++)
            contacts[j] = contacts[j+1];
    }

    cout<<"Delete contact successfull.";




}

void search_contact(Contact contacts[], int index)
{
    string first_name, last_name;
    cout<<"Enter Contact firstname: ";
    cin>>first_name;
    cout<<"Enter Contact lastname: ";
    cin>>last_name;

    int found_index_1 =  search(contacts, index, first_name);
    int found_index_2 = search(contacts, index, last_name);

    if(found_index_1 != found_index_2)
    {
        cout<<"Not found!!!";
        exit(1);
    }

    cout<<"\n\nContact Info:";
    cout<<" id: "<<contacts[found_index_1].id<<"\n firstname: "<<contacts[found_index_1].first_name<<
        "\n lastname: "<<contacts[found_index_1].last_name<<"\n number: "<<contacts[found_index_1].phone_number<<"\n\n";

}

void show_contacts(Contact contacts[], int index)
{
    cout<<" ------------------------------------------------------------------------------\n";
    cout<<"| ID   |  Contact firstname   |  Contact lastname    |  Contact number         |\n";
    cout<<" ----- + -------------------- + -------------------- + ----------------------- +\n";

    for(int i=0; i<index; i++)
    {
        cout<<"| "<<contacts[i].id<<"    | "<<contacts[i].first_name<<"                |   "<<contacts[i].last_name<<"            | "<<contacts[i].phone_number<<"           |\n";
        cout<<" ----- + -------------------- + -------------------- + ----------------------- +\n";
    }
}

void sort_contacts(Contact contacts[], int index)
{
    bubble_sort(contacts, index);

    show_contacts(contacts, index);
}

void menu()
{

    int index = 0;
    Contact contacts[1000];

    while(true)
    {
        int choice;
        cout<<"\n1- Create a contact.\n2- Edit a contact.\n3- Delete a contact.\n4- Contact's list."
            "\n5- Search a contact.\n6- Sort by name.\n7- Exit.\n\n";
        cin>>choice;

        switch(choice)
        {

        case 1:
        {
            create_contact(contacts, index);
            index++;
            break;
        }

        case 2:
        {
            edit_contact(contacts, index);
            break;
        }

        case 3:
        {
            delete_contact(contacts, index);
            break;
        }

        case 4:
        {
            show_contacts(contacts, index);
            break;
        }

        case 5:
        {
            search_contact(contacts, index);
            break;
        }

        case 6:
        {
            sort_contacts(contacts, index);
            break;
        }

        case 7:
        {
            exit(0);
        }

        default:
            cout<<"wrong input!!!";
        }
    }
}


