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
      name          user;         // account name for the user * Remember name is current value for EOS build
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

       bool isBagholder(name user) //check user bagholder status
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

       bool isStrongHands(name user) //check user stronghands status
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

       void create(   name     issuer,
                      asset    maximum_supply ); // Create ABG token

       void issue(    name     to, 
                      asset    quantity, 
                      string   memo ); // Issue token to address

       void transfer( name     from,
                      name     to,
                      asset    quantity,
                      string   memo ); // P2P transfer of tokens in network

       //***************************************
       //******** Entry & Exit points **********
       //***************************************

       void buy(name referral, int value_amount) //Buy ABG token 
       {
          purchaseTokens(value_amount, referral); //PSUEDO 
       }; 

       void reinvest(name user) //Convert tokens to dividends
       {
        if (isStrongHands() == true){

          //get dividends
          int dividends = myDividends(false); //retrieve referral business

          //send moeny to customer address += dividends * mag

          // get referral bonus

          // create buy order with withdrawn dividens

          //do
        }
       }; 


       void leave(name user) // Exit, same as withdraw
       {
          int tokens = token call of user //PSUEDO 
          if( tokens > 0){
            sell(tokens);
            withdraw();
          }
       };

       void withdraw(name user ) //Withdraw all earnings
       {
          if(isStrongHands() == true){
            int dividends() = myDividends(false);

            //send money to customer address += dividends * mag

            //get referal bonus

            //transfer divdiends

            //execute
          }
       };

       void sell(name user) //liquidate to EOS
       {
          if(isBagholder() == false){
            if(amount of tokens <= tokenbalance ledger){//PSUEDO 
              int tokens = amount of tokens //PSUEDO 
              int EOS = tokens to EOS //PSUEDO 
              int dividends = EOS / dividend fee //PSUEDO 
              int taxes = EOS - dividends //PSUEDO 

              // burn the tokens
              token supply = token supply - tokens //PSUEDO 
              token balance ledger = token balance - token supply //PSUEDO 

              // update dividends
              int payouts = int profitshare * tokens + (tax * mag) //PSUEDO 
              payouts to address -= payouts //PSUEDO 

              // Safety
              if(token supply > 0){//PSUEDO 
                //update dividends per token
                profitshare = profitshare + (dividends * mag)/ token supply)//PSUEDO 
              }
            }
          }
       };

       //***************************************
       //************** Actions ****************
       //***************************************

       void transfer( name         from,
                      name         to,
                      asset        quantity,
                      string       memo ){// P2P transfer of tokens in network, include fee here 10%?
        if(isBagholder(name user) == true){
          //withdraw dividends
          if(myDividends(true) >0){
            withdraw();
          }

          //10% of tokens returned to network
          int tokenfee = amount of tokens/dividend fee //PSUEDO 
          int tax = amount of tokens - token fee //PSUEDO 
          int dividends = tokens to EOS (token fee) //PSUEDO 

          //burn the fee tokens
          token supply = token supply - token fee //PSUEDO 

          token balance ledger = token - amount of tokens? //PSUEDO 
          token to address = token balance + taxes //PSUEDO 

          //update dividends

          payout to _customerAddress -= int profitshare * amount of tokens //PSUEDO 
          payouts to address += int profitshare * taxed tokens //PSUEDO 

          profitshare = profit share + (dividends * mag)/ token supply //PSUEDO 

          //execute 

          transfer(_customerAddress, to address, taxed tokens)//PSUEDO 



        }


       }

       //***************************************
       //*************** Info ******************
       //***************************************

       void totalBalance() //Get total EOS balance
       {};

       void totalSupply()  //Get total tokens
       {};

       void myTokens() //Retrieve tokens of caller
       {};

       void myDividends(bool referral_bonus,
                        name user) //Retrieve dividends of caller (taking bool true false)
       {
          return dividendOf(user);
       };

       void balanceOf() //Retrieve balance of address
       {};

       int dividendOf(name user) //Retrieve divdend of address
       {
          // int value = (profitshare * tokenbalance[user] - payoutsTo[user] / mag);
          int value = 0; // for testing purposes 
          return value;
       };

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
