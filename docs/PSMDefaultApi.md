# PSMDefaultApi

All URIs are relative to *https://pesamoni.com/api/live/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**transactionsPost**](PSMDefaultApi.md#transactionspost) | **POST** /transactions | 


# **transactionsPost**
```objc
-(NSURLSessionTask*) transactionsPostWithMethod: (NSString*) method
    amount: (NSString*) amount
    mobile: (NSString*) mobile
    holdername: (NSString*) holdername
    cardnumber: (NSString*) cardnumber
    cvv: (NSString*) cvv
    exp: (NSString*) exp
    currency: (NSString*) currency
    account: (NSString*) account
    reference: (NSString*) reference
    genericmsg: (NSString*) genericmsg
    token: (NSString*) token
    bouquet: (NSString*) bouquet
    payoption: (NSString*) payoption
    meternumber: (NSString*) meternumber
        completionHandler: (void (^)(PSMInlineResponse200* output, NSError* error)) handler;
```



Below are parameters and their respective expected responses. In order to try out the service, simply click Try it out.

### Example 
```objc
PSMDefaultConfiguration *apiConfig = [PSMDefaultConfiguration sharedConfig];

// Configure API key authorization: (authentication scheme: apipassword)
[apiConfig setApiKey:@"YOUR_API_KEY" forApiKeyIdentifier:@"apipassword"];
// Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
//[apiConfig setApiKeyPrefix:@"Bearer" forApiKeyIdentifier:@"apipassword"];

// Configure API key authorization: (authentication scheme: apiusername)
[apiConfig setApiKey:@"YOUR_API_KEY" forApiKeyIdentifier:@"apiusername"];
// Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
//[apiConfig setApiKeyPrefix:@"Bearer" forApiKeyIdentifier:@"apiusername"];


NSString* method = @"method_example"; // Enter a request method. To check for request methods <a href=''>click here</a>
NSString* amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* holdername = @"holdername_example"; // Enter name of payer for Visa/MasterCard transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* cardnumber = @"cardnumber_example"; // Enter the Visa/MasterCard cardnumber<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* cvv = @"cvv_example"; // Enter the Visa/MasterCard cvv<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* exp = @"exp_example"; // Enter the Visa/MasterCard expiry date in the format MM/YYYY e.g 07/2030<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* currency = @"currency_example"; // Enter the currency you intend to make the transaction for Visa/MasterCard based transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* account = @"account_example"; // Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)
NSString* reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* bouquet = @"bouquet_example"; // Enter the bouquet or package you would like to pay for<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
NSString* payoption = @"payoption_example"; // Enter your prefered payment option<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
NSString* meternumber = @"meternumber_example"; // Enter the meter number for the intended payment<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)

PSMDefaultApi*apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
              amount:amount
              mobile:mobile
              holdername:holdername
              cardnumber:cardnumber
              cvv:cvv
              exp:exp
              currency:currency
              account:account
              reference:reference
              genericmsg:genericmsg
              token:token
              bouquet:bouquet
              payoption:payoption
              meternumber:meternumber
          completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling PSMDefaultApi->transactionsPost: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **method** | **NSString***| Enter a request method. To check for request methods &lt;a href&#x3D;&#39;&#39;&gt;click here&lt;/a&gt; | 
 **amount** | **NSString***| Enter the amount you would like to request for. &lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept&lt;/b&gt;&lt;/p&gt; | 
 **mobile** | **NSString***| Enter the mobile number you would like to execute the above method in format 256.... or 254...&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime&lt;/b&gt;&lt;/p&gt; | [optional] 
 **holdername** | **NSString***| Enter name of payer for Visa/MasterCard transactions&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **cardnumber** | **NSString***| Enter the Visa/MasterCard cardnumber&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **cvv** | **NSString***| Enter the Visa/MasterCard cvv&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **exp** | **NSString***| Enter the Visa/MasterCard expiry date in the format MM/YYYY e.g 07/2030&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **currency** | **NSString***| Enter the currency you intend to make the transaction for Visa/MasterCard based transactions&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **account** | **NSString***| Enter the Pesamoni account you would like to use for this transaction&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; | [optional] 
 **reference** | **NSString***| Enter your user generated transaction reference&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **genericmsg** | **NSString***| Enter your user generated generic message for the requested transaction&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **token** | **NSString***| Enter your user generated token for the above mentioned method&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; | [optional] 
 **bouquet** | **NSString***| Enter the bouquet or package you would like to pay for&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; | [optional] 
 **payoption** | **NSString***| Enter your prefered payment option&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; | [optional] 
 **meternumber** | **NSString***| Enter the meter number for the intended payment&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; | [optional] 

### Return type

[**PSMInlineResponse200***](PSMInlineResponse200.md)

### Authorization

[apipassword](../README.md#apipassword), [apiusername](../README.md#apiusername)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

