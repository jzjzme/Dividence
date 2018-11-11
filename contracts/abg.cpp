#include <eosiolib/eosio.hpp>

using namespace eosio;


//***************************************
//************** Summary ****************
//***************************************

// Use of a community member (via smart contract) 
// that constantly reinvests dividends back into the economy
// This increases everyone's share proportionally, but regardless
// is optional. Maybe serves as a history of what happens if you 
// constantly stayed in the ecosystem. 

// Maybe serve as buyer of last resort? 

// The Last bag holder lols

CONTRACT abg : public eosio::contract {
  private:


  public:

  	using contract::contract;

  	 //***************************************
     //************** Actions ****************
     //***************************************

  	 //Whenever receives money, should reinvest dividends back into the market. 


  	 


 }








 EOSIO_DISPATCH( abg, (update) )
