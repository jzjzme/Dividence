#include <eosiolib/eosio.hpp>
#include <contracts/eosio.token/eosio.token.hpp>

using namespace eosio;


CONTRACT master : public eosio::contract {
  private:


    bool isnewuser( name user ) {
      auto master_index = _master.get_index<name("getbyuser")>();
      auto master_iterator = master_index.find(user.value);

      return master_iterator == master_index.end();
    }

    TABLE masterStruct{
      uint64_t      prim_key;     // primary key
      name          user;         // account name for the user
      bool          isBagholder;  // is bagholder bool
      bool          isStrongHands;// is stronghands bool
      uint64_t      timestamp;    // the store the last update block time

      // primary key
      auto primary_key() const { return prim_key; }
      // secondary key
      // only supports uint64_t, uint128_t, uint256_t, double or long double
      uint64_t get_by_user() const { return user.value; }

    }

    // create a multi-index table and support secondary key
    typedef eosio::multi_index< name("masterstruct"), masterstruct,
      indexed_by< name("getbyuser"), const_mem_fun<notestruct, uint64_t, &masterstruct::get_by_user> >
      > master_table;

    master_table _master;

  public:

    using contract::contract;

       //**************************************
       //************* Modifiers **************
       //**************************************

       bool isBagholder() //check user bagholder status
       {
          auto master_index = _master.get_index<name("getbyuser")>();
          auto &master_entry = master_index.get(user.value);

          if(myTokens() > 0){
            master_entry.isBagholder == true;
          }
          else{
            master_entry.isBagholder == false;
          }

          if (master_entry.isBagholder == true){
            return true;
          }
          else{
            return false;
          }
       };

       bool isStrongHands() //check user stronghands status
       {
          auto master_index = _master.get_index<name("getbyuser")>();
          auto &master_entry = master_index.get(user.value);

          if(myDividends(true) > 0){
            master_entry.isStrongHands == true;
          }
          else{
            master_entry.isStrongHands == false;
          }

          if (master_entry.isStrongHands == true){
            return true;
          }
          else{
            return false;
          }
       };

       //**************************************
       //********* Token Generation ***********
       //**************************************

       void create( account_name issuer,
                    asset        maximum_supply ); // Create ABG token

       void issue( account_name to, asset quantity, string memo ); // Issue token to address

       void transfer( account_name from,
                      account_name to,
                      asset        quantity,
                      string       memo ); // P2P transfer of tokens in network

       //***************************************
       //******** Entry & Exit points **********
       //***************************************


       void buy(address _referral) //Buy ABG token 
       {
          purchaseTokens(msg.value, _referral); //PSUEDO 
       }; 

       void reinvest() //Convert tokens to dividends
       {
        if (isStrongHands() == true){
          //get dividends
          int dividends = myDividends(false); //retrieve referral business

          address _customerAddress = msg.sender //PSUEDO 

          //send moeny to customer address += dividends * mag

          // get referral bonus

          // create buy order with withdrawn dividens

          //do
        }
       }; 


       void leave() // Exit, same as withdraw
       {
          address _customerAddress = msg.sender //PSUEDO 
          int tokens = token call of _customerAddress //PSUEDO 
          if( tokens > 0){
            sell(tokens);
            withdraw();
          }

       };

       void withdraw() //Withdraw all earnings
       {
          if(isStrongHands() == true){
            address = _customerAddress = msg.sender //PSUEDO 
            int dividends() = myDividends(false);

            //send money to customer address += dividends * mag

            //get referal bonus

            //transfer divdiends

            //execute
          }

       };

       void sell() //liquidate to EOS
       {};

       //***************************************
       //************** Actions ****************
       //***************************************

       void transfer( account_name from,
                      account_name to,
                      asset        quantity,
                      string       memo ); // P2P transfer of tokens in network, include fee here 10%?

       //***************************************
       //*************** Info ******************
       //***************************************

       void totalBalance() //Get total EOS balance
       {};

       void totalSupply()  //Get total tokens
       {};

       void myTokens() //Retrieve tokens of caller
       {};

       void myDividends() //Retrieve dividends of caller
       {};

       void balanceOf() //Retrieve balance of address
       {};

       void dividendOf() //Retrieve divdend of address
       {};

       void sellPrice() //Retrieve current ABG token sell price
       {};

       void buyPrice() //Retrieve current ABG token buy price
       {};

       void tokensReceived() //Frontend function call
       {};

       void EOSReceived() //Frontend function call
       {};

       //***************************************
       //*************** Admin *****************
       //***************************************

       void purchaseTokens() //System buy tokens
       {};

       void EOS_to_ABG() //Calculate sell value 
       {};
 }

 EOSIO_DISPATCH( master, (update) )
