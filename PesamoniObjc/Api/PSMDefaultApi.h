#import <Foundation/Foundation.h>
#import "PSMInlineResponse200.h"
#import "PSMApi.h"


@interface PSMDefaultApi: NSObject <PSMApi>

extern NSString* kPSMDefaultApiErrorDomain;
extern NSInteger kPSMDefaultApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(PSMApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// 
/// Below are parameters and their respective expected responses. In order to try out the service, simply click Try it out.
///
/// @param method Enter a request method. To check for request methods &lt;a href&#x3D;&#39;&#39;&gt;click here&lt;/a&gt;
/// @param amount Enter the amount you would like to request for. &lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept&lt;/b&gt;&lt;/p&gt;
/// @param mobile Enter the mobile number you would like to execute the above method in format 256.... or 254...&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime&lt;/b&gt;&lt;/p&gt; (optional)
/// @param holdername Enter name of payer for Visa/MasterCard transactions&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param cardnumber Enter the Visa/MasterCard cardnumber&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param cvv Enter the Visa/MasterCard cvv&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param exp Enter the Visa/MasterCard expiry date in the format MM/YYYY e.g 07/2030&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param currency Enter the currency you intend to make the transaction for Visa/MasterCard based transactions&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param account Enter the Pesamoni account you would like to use for this transaction&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request method &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; (optional)
/// @param reference Enter your user generated transaction reference&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param genericmsg Enter your user generated generic message for the requested transaction&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param token Enter your user generated token for the above mentioned method&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept&lt;/b&gt;&lt;/p&gt; (optional)
/// @param bouquet Enter the bouquet or package you would like to pay for&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; (optional)
/// @param payoption Enter your prefered payment option&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; (optional)
/// @param meternumber Enter the meter number for the intended payment&lt;p style&#x3D;\&quot;color:red\&quot;&gt;This method applies for request methods &lt;b&gt;paybills&lt;/b&gt;&lt;/p&gt; (optional)
/// 
///  code:200 message:"OK"
///
/// @return PSMInlineResponse200*
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



@end
