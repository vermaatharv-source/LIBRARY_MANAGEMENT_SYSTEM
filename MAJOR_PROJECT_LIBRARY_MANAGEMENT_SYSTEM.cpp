// LIBRARY MANAGEMENT SYSTEM

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int pin; //global scope variable

class book {
    public:
    string title;
    string author;
    long int id;

    // parametrized constructor

    book(string title, string author, long int id){
        // class specifier = parameter
        this->title = title;
        this->author = author;
        this->id = id;
    }

    void display(){
        cout<<"BOOK TITLE: "<<title<<endl;
        cout<<"BOOK AUTHOR: "<<author<<endl;
        cout<<"BOOK ID: "<<id<<endl;
    }
    
};
class member{
    public:
    string name;
    int id;

     member(string name, int id){
        this->name = name;
        this->id = id;
    }    
       
    void display_member(){
        cout<<"MEMBER NAME: "<<name<<endl;
        cout<<"MEMBER ID: "<<id<<endl;
        cout<<"----------------"<<endl;
    }
 
};
class issuedbooks{
    public:
    string title;
    string author;
    long int id;

    // parametrized constructor

    issuedbooks(string title, string author, long int id){
        // class specifier = parameter
        this->title = title;
        this->author = author;
        this->id = id;
    }
    void display_issuedbooks(){
        cout<<"BOOK TITLE: "<<title<<endl;
        cout<<"BOOK AUTHOR: "<<author<<endl;
        cout<<"BOOK ID: "<<id<<endl;
        cout<<"------------"<<endl;
    }
};
class library{ // called in the main function using lib as variable.
    public:

    // creating a vector for to save books in dynamic memory allocation

    vector<book> volume;
  // creating a void function add_book to insert books in dynamic memory


    void add_book(string title, string author, long int id){
        volume.push_back(book(title, author, id));
    }
bool remove_book_by_id(long int id){
    for(size_t i = 0; i < volume.size(); i++){   // loop through vector by index
        if(volume[i].id == id){
            cout << "THE BOOK WITH THE ID " << id << " EXISTS\n";
            volume[i].display();

            // erase the book at index i
            volume.erase(volume.begin() + i);

            cout << "THE FOLLOWING BOOK HAS BEEN REMOVED FROM THE DATABASE.\n";
            return true;
        }
    }
    cout << "THE BOOK WITH THE ID " << id << " DOES NOT EXIST\n";
    return false;
    }
    void display_all_books(){
        for(book &v : volume){
            v.display();
            cout<<"----------------"<<endl;
        }
    }
    bool search_book_by_id(int id){
         for(book &v : volume){
            if(v.id==id){
                cout<<"THE BOOK WITH THE ID "<<id<<" EXISTS"<<endl;
                v.display(); 
                return true;  
            } 
        } 
        cout<<"THE BOOK WITH THE ID "<<id<<" DOES NOT EXISTS"<<endl;
        return false;
    }
    string toUppercase(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 97 && s[i] <= 122) {
            s[i]  = s[i] - 32; // Subtracting 32 from any lowercase letter gives its uppercase equivalent.
        }
    }
    return s;
}
    bool search_book_by_title(string title){
        title = toUppercase(title);
        for(book &v : volume){
            if(v.title==title){
                cout<<"THE BOOK WITH THE TITLE "<<title<<" EXISTS"<<endl;
                v.display(); 
                return true;
            }
        }
        cout<<"THE BOOK WITH THE TITLE DOES NOT "<<title<<" EXISTS"<<endl;
        return false;
    }

    // creating a vector to save members

        vector<member> people;

    void add_member(string name, int id){
        people.push_back(member(name, id));
    }
    void display_all_member(){
        for( member &m : people){
            m.display_member();
        }
    }
    bool remove_member_by_id(long int id){
    for(size_t i = 0; i < people.size(); i++){   // loop through vector by index
        if(people[i].id == id){
            cout << "THE MEMBER WITH THE ID " << id << " EXISTS\n";
            people[i].display_member();

            // erase the book at index i
            people.erase(people.begin() + i);

            cout << "THE FOLLOWING MEMBER HAS BEEN REMOVED FROM THE DATABASE.\n";
            return true;
        }
    }
    cout << "THE MEMBER WITH THE ID " << id << " DOES NOT EXIST\n";
    return false;
    }

    // creating a vector to save issued books

    vector<issuedbooks> issued_books;

    void add_issuedbooks(string title, string author, long int id){
        issued_books.push_back(issuedbooks(title, author, id));
    }

    void display_allissuedbooks(){
        for(issuedbooks &x : issued_books){
            x.display_issuedbooks();
        }
    }
    bool issue_book_by_id(int id){
        for (issuedbooks &b : issued_books) {
        if (b.id == id) {
            cout << "BOOK WITH ID " << id << " IS ALREADY ISSUED!" << endl;
            return false;
        }
    }
        for(book &x : volume){
            if(x.id == id){
                cout<<"THE BOOK WITH THE ID "<<id<<" EXISTS IN THE DATABASE";
                x.display();
                cout<<"THE BOOK HAS BEEN ISSUED!"<<endl;
                // i converted object book to object issuedbooks.
                issued_books.push_back(issuedbooks(x.title, x.author, x.id));
                return true;
            }
        }
        cout<<"THE BOOK WITH THE ID "<<id<<" DOES NOT EXISTS IN THE DATABASE, ISSUING BOOK CANCELLED!";
        return false;
    }
    bool return_book_by_id(int id){
        for (issuedbooks &b : issued_books) {
        if (b.id == id){
            for(size_t i = 0; i < issued_books.size(); i++){   // loop through vector by index
            if(issued_books[i].id == id){
            
            // erase the book at index i
            issued_books.erase(issued_books.begin() + i);

            cout << "THE FOLLOWING BOOK HAS BEEN RETURNED.\n";
            return true;
        }
    }

        }
    }
    cout<<"THE BOOK WITH THE ID "<<id<<" DOES NOT EXISTS IN THE DATABASE, RETURNING BOOK CANCELLED!";
    return false;
}
};

void lock_access(int &pin){
    for(int i=1; i<=3; i++){
        cin>>pin;
        if(pin==2007){
            cout<<"\nWELCOME TO LIBRARY"<<endl;
            break;
        } else {
            if(i==3){
                cout<<"MAXIMUM ATTEMPTS REACHED! YOUR ACCESS TO LIBRARY SYSTEM HAS BEEN DECLINED";
                exit(0);
            }
            cout<<"INVALID PIN! PLEASE TRY AGAIN: ";
        }
    }

}
bool restart_menu(){
    cout<<"\nDO YOU WANT TO PROCESS ANOTHER FUNCTION?"<<endl;
        cout<<"1. YES"<<endl;
        cout<<"2. NO"<<endl;
        cout<<"PLEASE SELECT YOUR FUNCTION: "; 
        cin>>pin;
        if(pin==1){
            return true;
        } else {
            cout<<"THANKS FOR VISITING OUT LIBRARY MANAGEMENT SYSTEM.";
            exit(0);
            return false;
        }
}

int main(){

    // displaying all the local scope variable
    int choice;
    int point;
    long int book_id;
    string book_title;
    string book_author;
    string updated_book_title;
    string member_name;
    int member_id;
    int option;
    // MAIN CODE START HERE
    cout<<"\n\033[1m********* WELCOME TO LIBRARY SYSTEM **********\033[0m\n"<<endl;
    cout<<"PLEASE ENTER YOU FOUR DIGIT PIN TO LOGIN: ";
    
    lock_access(pin);
    library lib; // constructor call

    cout << "\nPLEASE SELECT YOUR LOGIN ROLE:\n1. LIBRARIAN\n2. MEMBER"<<endl;
    cout<<"ENTER YOUR CHOICE: "<<endl;
    cin>>point;
    

    // ADDING BOOKS TO THE LIBRARY DATABASE WHICH WILL SAVE IT IN BOOK OBJECT INSIDE VECTORS

lib.add_book("PRIDE AND PREJUDICE", "JANE AUSTEN", 1001);
lib.add_book("1984", "GEORGE ORWELL", 1002);
lib.add_book("TO KILL A MOCKINGBIRD", "HARPER LEE", 1003);
lib.add_book("THE GREAT GATSBY", "F. SCOTT FITZGERALD", 1004);
lib.add_book("MOBY-DICK", "HERMAN MELVILLE", 1005);
lib.add_book("WAR AND PEACE", "LEO TOLSTOY", 1006);
lib.add_book("CRIME AND PUNISHMENT", "FYODOR DOSTOEVSKY", 1007);
lib.add_book("THE CATCHER IN THE RYE", "J.D. SALINGER", 1008);
lib.add_book("BRAVE NEW WORLD", "ALDOUS HUXLEY", 1009);
lib.add_book("JANE EYRE", "CHARLOTTE BRONTË", 1010);

lib.add_book("WUTHERING HEIGHTS", "EMILY BRONTË", 1011);
lib.add_book("THE ODYSSEY", "HOMER", 1012);
lib.add_book("THE ILIAD", "HOMER", 1013);
lib.add_book("THE DIVINE COMEDY", "DANTE ALIGHIERI", 1014);
lib.add_book("HAMLET", "WILLIAM SHAKESPEARE", 1015);
lib.add_book("MACBETH", "WILLIAM SHAKESPEARE", 1016);
lib.add_book("OTHELLO", "WILLIAM SHAKESPEARE", 1017);
lib.add_book("KING LEAR", "WILLIAM SHAKESPEARE", 1018);
lib.add_book("A TALE OF TWO CITIES", "CHARLES DICKENS", 1019);
lib.add_book("GREAT EXPECTATIONS", "CHARLES DICKENS", 1020);

lib.add_book("OLIVER TWIST", "CHARLES DICKENS", 1021);
lib.add_book("DAVID COPPERFIELD", "CHARLES DICKENS", 1022);
lib.add_book("LES MISÉRABLES", "VICTOR HUGO", 1023);
lib.add_book("THE HUNCHBACK OF NOTRE-DAME", "VICTOR HUGO", 1024);
lib.add_book("ANNA KARENINA", "LEO TOLSTOY", 1025);
lib.add_book("THE BROTHERS KARAMAZOV", "FYODOR DOSTOEVSKY", 1026);
lib.add_book("NOTES FROM UNDERGROUND", "FYODOR DOSTOEVSKY", 1027);
lib.add_book("THE PICTURE OF DORIAN GRAY", "OSCAR WILDE", 1028);
lib.add_book("ULYSSES", "JAMES JOYCE", 1029);
lib.add_book("DUBLINERS", "JAMES JOYCE", 1030);

lib.add_book("THE SOUND AND THE FURY", "WILLIAM FAULKNER", 1031);
lib.add_book("ABSALOM, ABSALOM!", "WILLIAM FAULKNER", 1032);
lib.add_book("LOLITA", "VLADIMIR NABOKOV", 1033);
lib.add_book("PALE FIRE", "VLADIMIR NABOKOV", 1034);
lib.add_book("THE STRANGER", "ALBERT CAMUS", 1035);
lib.add_book("THE PLAGUE", "ALBERT CAMUS", 1036);
lib.add_book("THE MYTH OF SISYPHUS", "ALBERT CAMUS", 1037);
lib.add_book("ONE HUNDRED YEARS OF SOLITUDE", "GABRIEL GARCÍA MÁRQUEZ", 1038);
lib.add_book("LOVE IN THE TIME OF CHOLERA", "GABRIEL GARCÍA MÁRQUEZ", 1039);
lib.add_book("CHRONICLE OF A DEATH FORETOLD", "GABRIEL GARCÍA MÁRQUEZ", 1040);

lib.add_book("DON QUIXOTE", "MIGUEL DE CERVANTES", 1041);
lib.add_book("THE OLD MAN AND THE SEA", "ERNEST HEMINGWAY", 1042);
lib.add_book("FOR WHOM THE BELL TOLLS", "ERNEST HEMINGWAY", 1043);
lib.add_book("A FAREWELL TO ARMS", "ERNEST HEMINGWAY", 1044);
lib.add_book("THE SUN ALSO RISES", "ERNEST HEMINGWAY", 1045);
lib.add_book("CATCH-22", "JOSEPH HELLER", 1046);
lib.add_book("SLAUGHTERHOUSE-FIVE", "KURT VONNEGUT", 1047);
lib.add_book("CAT'S CRADLE", "KURT VONNEGUT", 1048);
lib.add_book("BREAKFAST OF CHAMPIONS", "KURT VONNEGUT", 1049);
lib.add_book("INVISIBLE MAN", "RALPH ELLISON", 1050);

lib.add_book("BELOVED", "TONI MORRISON", 1051);
lib.add_book("SONG OF SOLOMON", "TONI MORRISON", 1052);
lib.add_book("SULA", "TONI MORRISON", 1053);
lib.add_book("THE BLUEST EYE", "TONI MORRISON", 1054);
lib.add_book("MIDDLEMARCH", "GEORGE ELIOT", 1055);
lib.add_book("SILAS MARNER", "GEORGE ELIOT", 1056);
lib.add_book("DANIEL DERONDA", "GEORGE ELIOT", 1057);
lib.add_book("FRANKENSTEIN", "MARY SHELLEY", 1058);
lib.add_book("DRACULA", "BRAM STOKER", 1059);
lib.add_book("THE TIME MACHINE", "H.G. WELLS", 1060);

lib.add_book("THE WAR OF THE WORLDS", "H.G. WELLS", 1061);
lib.add_book("THE INVISIBLE MAN", "H.G. WELLS", 1062);
lib.add_book("THE ISLAND OF DOCTOR MOREAU", "H.G. WELLS", 1063);
lib.add_book("FAHRENHEIT 451", "RAY BRADBURY", 1064);
lib.add_book("THE MARTIAN CHRONICLES", "RAY BRADBURY", 1065);
lib.add_book("DUNE", "FRANK HERBERT", 1066);
lib.add_book("CHILDREN OF DUNE", "FRANK HERBERT", 1067);
lib.add_book("GOD EMPEROR OF DUNE", "FRANK HERBERT", 1068);
lib.add_book("FOUNDATION", "ISAAC ASIMOV", 1069);
lib.add_book("FOUNDATION AND EMPIRE", "ISAAC ASIMOV", 1070);

lib.add_book("SECOND FOUNDATION", "ISAAC ASIMOV", 1071);
lib.add_book("I, ROBOT", "ISAAC ASIMOV", 1072);
lib.add_book("THE CAVES OF STEEL", "ISAAC ASIMOV", 1073);
lib.add_book("THE NAKED SUN", "ISAAC ASIMOV", 1074);
lib.add_book("THE ROBOTS OF DAWN", "ISAAC ASIMOV", 1075);
lib.add_book("NEUROMANCER", "WILLIAM GIBSON", 1076);
lib.add_book("COUNT ZERO", "WILLIAM GIBSON", 1077);
lib.add_book("MONA LISA OVERDRIVE", "WILLIAM GIBSON", 1078);
lib.add_book("SNOW CRASH", "NEAL STEPHENSON", 1079);
lib.add_book("CRYPTONOMICON", "NEAL STEPHENSON", 1080);

lib.add_book("THE DIAMOND AGE", "NEAL STEPHENSON", 1081);
lib.add_book("ANATHEM", "NEAL STEPHENSON", 1082);
lib.add_book("THE HOBBIT", "J.R.R. TOLKIEN", 1083);
lib.add_book("THE FELLOWSHIP OF THE RING", "J.R.R. TOLKIEN", 1084);
lib.add_book("THE TWO TOWERS", "J.R.R. TOLKIEN", 1085);
lib.add_book("THE RETURN OF THE KING", "J.R.R. TOLKIEN", 1086);
lib.add_book("THE SILMARILLION", "J.R.R. TOLKIEN", 1087);
lib.add_book("HARRY POTTER AND THE SORCERER'S STONE", "J.K. ROWLING", 1088);
lib.add_book("HARRY POTTER AND THE CHAMBER OF SECRETS", "J.K. ROWLING", 1089);
lib.add_book("HARRY POTTER AND THE PRISONER OF AZKABAN", "J.K. ROWLING", 1090);

lib.add_book("HARRY POTTER AND THE GOBLET OF FIRE", "J.K. ROWLING", 1091);
lib.add_book("HARRY POTTER AND THE ORDER OF THE PHOENIX", "J.K. ROWLING", 1092);
lib.add_book("HARRY POTTER AND THE HALF-BLOOD PRINCE", "J.K. ROWLING", 1093);
lib.add_book("HARRY POTTER AND THE DEATHLY HALLOWS", "J.K. ROWLING", 1094);
lib.add_book("THE HUNGER GAMES", "SUZANNE COLLINS", 1095);
lib.add_book("CATCHING FIRE", "SUZANNE COLLINS", 1096);
lib.add_book("MOCKINGJAY", "SUZANNE COLLINS", 1097);
lib.add_book("THE MAZE RUNNER", "JAMES DASHNER", 1098);
lib.add_book("THE SCORCH TRIALS", "JAMES DASHNER", 1099);
lib.add_book("THE DEATH CURE", "JAMES DASHNER", 1100);

// adding members to the database:-

lib.add_member("Vibhor", 1);
lib.add_member("Tanmay Tyagi", 2);
lib.add_member("Abhinav", 3);
lib.add_member("Shashwat Bhatt", 4);
lib.add_member("Harshit", 5);
lib.add_member("Tanishq Pal", 6);
while(true){
    if(point==1){// here the code for librarian will be entered
        
        cout<<"FUNCTIONS TO ACCESS: \n"<<endl;
        string menu[] = {
            "1: View All Books",
            "2: Search Book by ID",
            "3: Search Book by Title",
            "4: Add New Book",
            "5: Remove Book by ID",
            "6: View All Members",
            "7: Add New Member",
            "8: Remove Member",
            "9: View Issued Books",
            "0: Exit"
        };
        for(int i=0; i<10; i++){ 
            cout<<menu[i]<<endl;
        }
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"ALL THE BOOKS IN THE DATABASE ARE: \n"<<endl;
            lib.display_all_books();
            restart_menu();
            break;
            case 2: 
            cout<<"PLEASE ENTER THE ID OF THE BOOK: "<<endl;
            cin>>book_id;
            lib.search_book_by_id(book_id);
            restart_menu();
            break;
            case 3:
            cout<<"PLEASE ENTER THE NAME OF THE BOOK: "<<endl;
            cin.ignore(); //to skip input buffer,,, necessary to use before getline() function;
            getline(cin, book_title);
            lib.search_book_by_title(book_title);
            restart_menu();
            break;
            case 4:
            cout<<"TO ADD A NEW BOOK IN THE LIBRARY DATABASE, PLEASE ENTER THE FOLLOWING INFORMATION: "<<endl;
            cout<<"PLEASE ENTER THE TITLE OF THE BOOK: "<<endl;
            cin.ignore();
            getline(cin, book_title);
            cout<<"PLEASE ENTER THE AUTHOR OF THE BOOK: "<<endl;
            cin.ignore();
            getline(cin, book_author);
            cout<<"PLEASE ENTER THE ID OF THE BOOK: "<<endl;
            cin>>book_id;
            lib.add_book(book_title, book_author, book_id);
            cout<<"THE FOLLOWING BOOK HAS BEEN ADDED, THIS IS THE UPDATED LIST OF BOOKS: ";
            lib.display_all_books();
            restart_menu();
            break;
            case 5:
            cout<<"ENTER THE BOOK ID TO REMOVE FROM THE DATABASE: ";
            cin>>book_id;
            lib.remove_book_by_id(book_id);
            restart_menu();
            break;
            case 6: 
            cout<<"ALL MEMBERS ARE AS FOLLOWS: \n";
            lib.display_all_member();
            restart_menu();
            break;
            case 7:
            cout<<"TO ADD A NEW MEMBER IN THE LIBRARY DATABASE, PLEASE ENTER THE FOLLOWING INFORMATION: "<<endl;
            cout<<"ENTER THE NAME OF THE MEMBER: "<<endl;
            cin.ignore();
            getline(cin, member_name);
            cout<<"ENTER THE ID OF THE MEMBER: "<<endl;
            cin>>member_id;
            lib.add_member(member_name, member_id);
            cout<<"THE FOLLOWING MEMBER HAS BEEN ADDED, THIS IS THE UPDATED LIST OF MEMBERS: ";
            lib.display_all_member();
            restart_menu();
            break;
            case 8:
            cout<<"ENTER THE ID OF THE MEMBER TO REMOVE: "<<endl;
            cin>>member_id;
            lib.remove_member_by_id(member_id);
            cout<<"THE UPDATED LIST OF MEMBERS IN THE DATABASE IS: "<<endl;
            lib.display_all_member();
            restart_menu();
            break;
            case 9:
            cout<<"ALL THE ISSUED BOOKS IN THE DATABASE:"<<endl;
            lib.display_allissuedbooks();
            restart_menu();
            break;
            case 0:
            cout<<"THANKS FOR USING OUR LIBRARY!";
            exit(0);
            default:
            cout<<"INCORRECT OPTIONS CHOOSED! PLEASE TRY AGAIN"<<endl;
            restart_menu();
        }
        
    } else if(point==2){// here the code for a member will be entered;
        
        string menu1[] = {
        "1. VIEW ALL BOOKS",
        "2. ISSUE BOOK",
        "3. MY ISSUED BOOKS",
        "4. RETURN BOOK",
        "0. EXIT"
    };

    for(int i=0; i<5; i++){
        cout<<menu1[i]<<endl;
    }

    cin>>option;
    switch(option){
        case 1:
        cout<<"ALL THE BOOKS IN THE LIBRARY ARE: "<<endl;
        lib.display_all_books();
        restart_menu();
        break;
        case 2: 
        cout<<"PLEASE ENTER THE ID OF THE BOOK TO ISSUE: "<<endl;
        cin>>book_id;
        lib.issue_book_by_id(book_id);
        restart_menu();
        break;
        case 3:
        cout<<"ALL ISSUED BOOKS IN THE DATABASE ARE: "<<endl;
        lib.display_allissuedbooks();
        restart_menu();
        break;
        case 4:
        cout<<"ALL ISSUED BOOKS IN THE DATABASE ARE: "<<endl;
        lib.display_allissuedbooks();
        cout<<"ENTER THE ID OF THE BOOK TO RETURN: "<<endl;
        cin>>book_id;
        lib.return_book_by_id(book_id);
        restart_menu();
        break;
        case 0:
        cout<<"THANKS FOR USING OUR LIBRARY!";
        exit(0);
        default:
        cout<<"INCORRECT OPTIONS CHOOSED! PLEASE TRY AGAIN"<<endl;
        restart_menu();
        }  
    } else {
        cout << "INVALID CHOICE!, RELOAD THE SYSTEM AGAIN.";
        restart_menu();   
    }
}
  return 0;  
}