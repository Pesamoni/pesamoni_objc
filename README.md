# Pesamoni

## Requirements

The SDK requires [**ARC (Automatic Reference Counting)**](http://stackoverflow.com/questions/7778356/how-to-enable-disable-automatic-reference-counting) to be enabled in the Xcode project.

## Installation & Usage
### Install from the [Pesamoni Github repo](https://github.com/Pesamoni/pesamoni_objc) using [CocoaPods](https://cocoapods.org/)

Add the following to the Podfile:

```ruby
pod 'PesamoniObjc', :git => 'https://github.com/Pesamoni/pesamoni_objc.git'
```

Put the SDK under your project folder (e.g. /path/to/objc_project/Vendor/PesamoniObjc) and then add the following to the Podfile:

```ruby
pod 'PesamoniObjc', :path => 'Vendor/PesamoniObjc'
```

## Quick Start Example
### Recommendation

It's recommended to create an instance of ApiClient per thread in a multi-threaded environment to avoid any potential issues.

Import the following:

```objc
#import <PesamoniObjc/PSMApiClient.h>
#import <PesamoniObjc/PSMDefaultConfiguration.h>
// load models
#import <PesamoniObjc/PSMInlineResponse200.h>
// load API classes for accessing endpoints
#import <PesamoniObjc/PSMDefaultApi.h>

```

## Getting Started

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

```

### Accepting funds from mobile subscriber
```objc
// you can either use method acreceive or acreceivekeac as explained below
// method acreceive
// This method enables you receive funds from a mobile subscriber in your registered native currency on the Pesamoni platform. If for instance your account is registered in currency UGX and you request money from a Kenyan number e.g 254712346789, a Pesamoni exchange rate will automatically be applied and money deposited into your Pesamoni wallet in your default currency
// method acreceivekeac
// You can have two native currencies on your Pesamoni account on request. If you would like to deposit funds from a mobile subscriber to your Kenyan Pesamoni wallet account then this is the method you use.
// example
NSString* *method = @"acreceive"; // Enter a request method. To check for request methods <a href=''>click here</a>
NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    mobile:mobile
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];
```

### Sending funds to a mobile subscriber

```objc
// you can either use method acsend or acsendkeac as explained below
// acsend
// This method enables you send funds to a mobile subscriber in your registered native currency on the Pesamoni platform. If for instance your account is registered in currency UGX and you send money to a kenyan number e.g 254712346789, a Pesamoni exchange rate will automatically be applied and the equivalent exchange amount deducted from your Pesamoni wallet in your default currency
// acsendkeac
// You can have two native currencies on your Pesamoni account on request. If you would like to send funds from your Pesamoni wallet to a mobile subscriber from your Kenyan Pesamoni wallet account then this is the method you use.
NSString* *method = @"acsend"; // Enter a request method. To check for request methods <a href=''>click here</a>
NSString* *amount = @"amount_example"; // Enter the amount you would like to send funds to. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    mobile:mobile
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];
```

### Accepting Card Payments e.g VISA/MASTERCARD

```objc
NSString* *method = @"cardaccept"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *holdername = @"holdername_example"; // Enter name of payer for Visa/MasterCard transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *cardnumber = @"cardnumber_example"; // Enter the Visa/MasterCard cardnumber<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *cvv = @"cvv_example"; // Enter the Visa/MasterCard cvv<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *exp = @"exp_example"; // Enter the Visa/MasterCard expiry date in the format MM/YYYY e.g 07/2030<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *currency = @"currency_example"; // Enter the currency you intend to make the transaction for Visa/MasterCard based transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    holdername:holdername
    cardnumber:cardnumber
    cvv:cvv
    exp:exp
    currency:currency
    mobile:mobile
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];
```

### Bank transfers

```objc
NSString* *method = @"acsendbank"; // Enter a request method. To check for request methods <a href=''>click here</a>
// / you can either use method acsendbank or acsendbankeac as explained below
// acsendbank
// This method enables you send funds to a users bank account. A Pesamoni exchange rate will automatically be applied and the equivalent exchange amount deposited to your bank account dependent on your default currency.
// acsendbankeac
// You can have two native currencies on your Pesamoni account on request. If you would like to send funds from your Pesamoni wallet to a mobile subscriber from your Kenyan Pesamoni wallet account then this is the method you use.
NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *currency = @"currency_example"; // Enter the currency you intend to make the transaction for Visa/MasterCard based transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *account = @"account_example"; // Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)

NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    mobile:currency
    account:account
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];

```
### Sending Airtime to a mobile subsriber

```objc

NSString* *method = @"sendairtime"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    mobile:mobile
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];

```
### Sending to a Pesamoni users wallet

```objc
NSString* *method = @"pesab2c"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *account = @"account_example"; // Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    account:account
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];
```

### Accepting funds from a Pesamoni user

```objc
NSString* *method = @"pesac2b"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *account = @"account_example"; // Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    account:account
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];

```

### Paying Utility Bills

```objc
NSString* *method = @"paybills"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *amount = @"amount_example"; // Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p>
NSString* *mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* *currency = @"currency_example"; // Enter the currency you intend to make the transaction for Visa/MasterCard based transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
NSString* *account = @"account_example"; // Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)
NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *bouquet = @"bouquet_example"; // Enter the bouquet or package you would like to pay for<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
NSString* *payoption = @"payoption_example"; // Enter your prefered payment option<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
NSString* *meternumber = @"meternumber_example"; // Enter the meter number for the intended payment<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)

PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    amount:amount
    mobile:mobile
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
                                NSLog(@"Error: %@", error);
                            }
                        }];

```

### Checking your Pesamoni Business Wallet Balance

```objc

NSString* *method = @"transactionstatus"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    reference:reference
    
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];

```

### Sending SMS to a mobile subscriber

```objc
NSString* *method = @"sendsms"; // Enter a request method. To check for request methods <a href=''>click here</a>

NSString* *mobile = @"mobile_example"; // Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
NSString* *message = @"message_example"; // Enter the message you would like to send

NSString* *reference = @"reference_example"; // Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *genericmsg = @"genericmsg_example"; // Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
NSString* *token = @"token_example"; // Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
PSMDefaultApi *apiInstance = [[PSMDefaultApi alloc] init];

[apiInstance transactionsPostWithMethod:method
    mobile:mobile
    message:message
    reference:reference
    genericmsg:genericmsg
    token:token
              completionHandler: ^(PSMInlineResponse200* output, NSError* error) {
                            if (output) {
                                NSLog(@"%@", output);
                            }
                            if (error) {
                                NSLog(@"Error: %@", error);
                            }
                        }];
```

## Documentation for API Endpoints

All Endpoint URIs are relative to https://pesamoni.com/api/live/v1/transactions

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/Pesamoni.

## License

The Objective c library is available as open source under the terms of the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0).




