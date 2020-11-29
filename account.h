class Account
{
    private:
        string firstName;
        string lastName;
        string phoneNumber;
        string accountNumber;
        string address;
        string dateOpened;
        string dateClosed;

        double balance;
        double intrestRate;
        double monthlyFee;

        bool status;    // open = true ---- closed = false

    public:
        Account()
        {
            string input;
            cout<<"Enter inital balance: "<<endl;
            getline(cin,input);
            balance = stod(input);
            cout<<"Enter First Name: "<<endl;
            getline(cin,input);
            firstName = input;
            cout<<"Enter Last Name: "<<endl;
            getline(cin,input);
            lastName = input;
            cout<<"Enter Phone Number: "<<endl;
            getline(cin,input);
            phoneNumber = input;
            cout<<"Enter Address: "<<endl;
            getline(cin,input);
            address = input;
            
        }
        //======================================================================================
        //            setters
        //======================================================================================
        void setfirstName( string x)
        {
            firstName = x;
        }

        void setlastName( string x)
        {
            lastName = x;
        }

        void setphoneNumber( string x)
        {
            phoneNumber = x;
        }

        void setaccountNumber( string x)
        {
            accountNumber = x;
        }

        void setaddress( string x)
        {
            address = x;
        }

        void setdateOpened( string x)
        {
            dateOpened = x;
        }

        void setdateClosed( string x)
        {
            dateClosed = x;
        }

        void setbalanced( double x)
        {
            balance = x;
        }

        void setinterestRate( double x)
        {
            intrestRate = x;
        }

        void setmonthlyFee( double x)
        {
            monthlyFee = x;
        }

        void setstatus( bool x)
        {
            status = x;
        }

        //======================================================================================
        //            getters
        //======================================================================================
        string getfirstName()
        {
            return firstName;
        }

        string setlastName()
        {
            return lastName;
        }

        string setphoneNumber()
        {
            return phoneNumber;
        }

        string setaccountNumber()
        {
            return accountNumber;
        }

        string setaddress()
        {
            return address;
        }

        string setdateOpened()
        {
            return dateOpened;
        }

        string setdateClosed()
        {
           return dateClosed;
        }

        double setbalanced()
        {
            return balance;
        }

        double setinterestRate()
        {
            return intrestRate;
        }

        double setmonthlyFee()
        {
            return monthlyFee;
        }

        bool setstatus()
        {
            return status;
        }

        
};

class DailyCheckingAccount : public Account
{

    public:
        DailyCheckingAccount()
        {
            setmonthlyFee(0.0);
            setinterestRate(0.0);
        }
};

class DailySavingAccount : public Account
{

    public:
        DailySavingAccount()
        {
            setmonthlyFee(0.0);
            string input;
            cout<<"Enter Interest Rate: "<<endl;
            getline(cin,input);
            setinterestRate(stod(input));
        }
};