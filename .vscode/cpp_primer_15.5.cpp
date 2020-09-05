#include <iostream>
//////////////////////////////////////////////////////////////////////////////////////////////
class Base
{
public:
friend void Friend_Base(Base&);
    void Base_pub_function();
    int Base_pub_mem;
    int B_f(){return Base_prot_mem;}  // call from inside no problem to access either prot_mem;
    char B_g() { return Base_priv_mem; } //or, priv_mem
protected:
    int Base_prot_mem;
private:
    char Base_priv_mem;
};
void Friend_Base(Base &s){s.Base_priv_mem = 0;}//// from here you can see the friend actually broken the capsle rule this is not good
///////////////////////////////////////////////////////////////////////////////////////////////
//below are 2nd layer
class Pub_Derv : public Base
{   friend void Friend_Pub_Derv(Pub_Derv &);
    int p() {return Base_pub_mem;} //#0 no problem to access Base public member from inside
    int f() { return Base_prot_mem; }  //#1 OK to access protected member from inside, copmare #2
    char g() { return Base_priv_mem; } //Error priv_mem inaccessble
    
    private:
    int j;
};
void Friend_Pub_Derv (Pub_Derv &s){ s.Base_pub_mem=0;}//#5  as well as Base_pub_mem
void Friend_Pub_Derv (Pub_Derv &s){ s.Base_prot_mem=0;}//#6  as well as Base_prot_mem
void Friend_Pub_Derv (Pub_Derv &s){ s.Bass_priv_mem=0;}// #7 but private member is not able to see
void Friend_Pub_Derv (Pub_Derv &s){s.j=0;} //#8 j is the private member of Pub_Derv its own. so friend shall
//have no problem to access. unlike Bass_priv_mem
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
struct  pub_Derived_from_Pub_Derv : public Pub_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pro_Derived_from_Pub_Derv : protected Pub_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pri_Derived_from_Pub_Derv : private Pub_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
///////////////////////////////////////////////////////////////////////////////////////////////
struct  Prote_Derv : protected Base
{   friend void Friend_Prote_Derv(Prote_Derv &);
    int p2() {return Base_pub_mem;} // no problem to access Base public member from inside
    int f2() const { return Base_prot_mem; } // that private Base is the same as derive from public Base.
    int g2() const { return Base_priv_mem; } // that private Base is the same as derive from public Base.
};
void Friend_Prote_Derv (Prote_Derv &s){ s.Base_pub_mem=0;}//#5  as well as Base_pub_mem
void Friend_Prote_Derv (Prote_Derv &s){ s.Base_prot_mem=0;}//#6  as well as Base_prot_mem
void Friend_Prote_Derv (Prote_Derv &s){ s.Base_priv_mem=0;}// #7 but private member is not able to see
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
struct  pub_Derived_from_Prot_Derv : public Prote_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pro_Derived_from_Prot_Derv : protected Prote_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pri_Derived_from_Prot_Derv : private Prote_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
///////////////////////////////////////////////////////////////////////////////////////////////
struct  Priv_Derv : private Base
{   friend void Friend_Priv_Derv(Priv_Derv &);
    int p1() {return Base_pub_mem;} // no problem to access Base public member from inside
    int f1() const { return Base_prot_mem; } // that private Base is the same as derive from public Base.
    int g1() const { return Base_priv_mem; } // that private Base is the same as derive from public Base.
};
void Friend_Priv_Derv (Priv_Derv &s){ s.Base_pub_mem=0;}//#5  as well as Base_pub_mem
void Friend_Priv_Derv (Priv_Derv &s){ s.Base_prot_mem=0;}//#6  as well as Base_prot_mem
void Friend_Priv_Derv (Priv_Derv &s){ s.Base_priv_mem=0;}// #7 but private member is not able to see
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
struct  pub_Derived_from_Priv_Derv : public Priv_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pro_Derived_from_Priv_Derv : protected Priv_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
struct  pri_Derived_from_Priv_Derv : private Priv_Derv{
    int use_base() {return Base_pub_mem;}
    int use_base() {return Base_prot_mem;}
    int use_base() {return Base_priv_mem;}
};
/* conclution: from inside, the derive access specifier different wont affect the accessble right:
// public and protected member no problem to access but private can't been access.
//imply: public or private in the "class derivation list" , will just impact 3rd layer and outside caller */
void clobber_not_friend (Prote_Derv &s) {s.Base_pub_mem = 0;} // see as we can see , compare to #5 , clobber_not_friend couldn't access the pub mem 
//becasue Prote_Derv pub_mem --- inherant from base,  is wearing a protected cloth, thus, it was not able to access by none_friend . 
void clobber_not_friend (Prote_Derv &s) {s.Base_prot_mem = 0;} // see as we can see , compare to #6, clobber_not_friend couldn't access the prot mem 
// it is the same reason, the protected derive from Base, all the data member wearing a protected function
////////////////////////////////////////////////////////////////////////////////////////////////


/* conclution: althouht here is access from 'inside' but actually the third layer is looking for the 2nd layer member property
since the 2nd layer is inherant from base using the access identifier, the public and protected become private if the accessble 
identifier is private (Priv_Deriv) so the Base_pub-mem inside the struct Priv_Deriv became private
so when the Derived_from_Priv_Derv using Base_pub_mem, even from inside, complier won't allow.
*/
int main()
{
// now we test access from <OUTSIDE>:
    Base baseObject;
    baseObject.Base_pub_function();// public member and function able to access
    baseObject.Base_prot_mem; //#2 outside caller couldn't call prot_member from outside
    //compare to #1 , same: private mem also can NOT been called.
    // this is the whole idea of the protection or private design for: outside only able to call the public function or data member
    std::cout << baseObject.Base_priv_mem << std::endl;// same, private member was inaccessble aslo
    std::cout << baseObject.B_f() << std::endl; // but they (protected & private) are accessble through B_f() function since this function is Public
    Pub_Derv d1;
    d1.Base_pub_function(); //#3 outside caller still able to access pub_mem, compare to #4
    d1.Bass_prot_mem;  //outside caller NOT able to access protected member same as #2
    //no need to mention private 
    Priv_Derv d2;
    d2.Base_pub_function(); //#4 Error: d2 is outside caller but is from private Base, compare to #3
    //so EVEN public member can't be accessed from outside, it became private
    // no need to mention protected and private
    Prote_Derv d3;
     std::cout << d3.Base_pub_mem<< std::endl;// as you can see the protected member was inaccessble from 'outside'
    
    

    pub_Derived_from_Pub_Derv d4;
    std::cout << d4.Base_pub_mem << std::endl;
    std::cout << d4.Base_prot_mem << std::endl;
    pro_Derived_from_Pub_Derv d5;
    std::cout << d5.Base_pub_mem << std::endl;
    pri_Derived_from_Pub_Derv d6;
    std::cout << d6.Base_pub_mem << std::endl;

    pub_Derived_from_Prot_Derv d7;
    std::cout << d7.Base_pub_mem << std::endl;
    pro_Derived_from_Prot_Derv d8;
    std::cout << d8.Base_pub_mem << std::endl;
    pri_Derived_from_Prot_Derv d9;
    std::cout << d9.Base_pub_mem << std::endl;

    pub_Derived_from_Priv_Derv d10;
    std::cout << d10.Base_pub_mem << std::endl;
    pro_Derived_from_Priv_Derv d11;
    std::cout << d11.Base_pub_mem << std::endl;
    pri_Derived_from_Priv_Derv d12;
    std::cout << d12.Base_pub_mem << std::endl;

    system("pause");
    return 0;
}
