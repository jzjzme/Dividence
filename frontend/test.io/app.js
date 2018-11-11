import { Api, JsonRpc, RpcError, JsSignatureProvider } from 'eosjs';

const defaultPrivateKey = ""; // for the main address
const signatureProvider = new JsSignatureProvider([defaultPrivateKey]);



const rpc = new JsonRpc(endpoint);
const signatureProvider = new JsSignatureProvider([privateKey]);
const api = new Api({ rpc, signatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() });

//WRITING THE API DOE Needs work

function buy(string account, int value){
	const result = await api.transact({
        actions: [{
          account: "dividence",
          name: actionName,
          authorization: [{
            actor: account,
            permission: 'active',
          }],
          data: value,
        }]
      }, {
        blocksBehind: 3,
        expireSeconds: 30,
      });
}

function sell(string account, int value){
	const result = await api.transact({
        actions: [{
          account: "dividence",
          name: actionName,
          authorization: [{
            actor: account,
            permission: 'active',
          }],
          data: value,
        }]
      }, {
        blocksBehind: 3,
        expireSeconds: 30,
      });
}

function withdraw(string account, int value){
	const result = await api.transact({
        actions: [{
          account: "dividence",
          name: actionName,
          authorization: [{
            actor: account,
            permission: 'active',
          }],
          data: value,
        }]
      }, {
        blocksBehind: 3,
        expireSeconds: 30,
      });
}

function reinvest(string account, int value){
	const result = await api.transact({
        actions: [{
          account: "dividence",
          name: actionName,
          authorization: [{
            actor: account,
            permission: 'active',
          }],
          data: value,
        }]
      }, {
        blocksBehind: 3,
        expireSeconds: 30,
      });
}
try {
  const result = await api.transact({
  ...
} catch (e) {
  console.log('\nCaught exception: ' + e);
  if (e instanceof RpcError)
    console.log(JSON.stringify(e.json, null, 2);
}