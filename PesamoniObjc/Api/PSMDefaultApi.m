#import "PSMDefaultApi.h"
#import "PSMQueryParamCollection.h"
#import "PSMApiClient.h"
#import "PSMInlineResponse200.h"


@interface PSMDefaultApi ()

@property (nonatomic, strong, readwrite) NSMutableDictionary *mutableDefaultHeaders;

@end

@implementation PSMDefaultApi

NSString* kPSMDefaultApiErrorDomain = @"PSMDefaultApiErrorDomain";
NSInteger kPSMDefaultApiMissingParamErrorCode = 234513;

@synthesize apiClient = _apiClient;

#pragma mark - Initialize methods

- (instancetype) init {
    return [self initWithApiClient:[PSMApiClient sharedClient]];
}


-(instancetype) initWithApiClient:(PSMApiClient *)apiClient {
    self = [super init];
    if (self) {
        _apiClient = apiClient;
        _mutableDefaultHeaders = [NSMutableDictionary dictionary];
    }
    return self;
}

#pragma mark -

-(NSString*) defaultHeaderForKey:(NSString*)key {
    return self.mutableDefaultHeaders[key];
}

-(void) setDefaultHeaderValue:(NSString*) value forKey:(NSString*)key {
    [self.mutableDefaultHeaders setValue:value forKey:key];
}

-(NSDictionary *)defaultHeaders {
    return self.mutableDefaultHeaders;
}

#pragma mark - Api Methods

///
/// 
/// Below are parameters and their respective expected responses. In order to try out the service, simply click Try it out.
///  @param method Enter a request method. To check for request methods <a href=''>click here</a> 
///
///  @param amount Enter the amount you would like to request for. <p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, acsendbank, pesab2c, sendairtime, cardaccept</b></p> 
///
///  @param mobile Enter the mobile number you would like to execute the above method in format 256.... or 254...<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, senderid, sendsms, sendairtime</b></p> (optional)
///
///  @param holdername Enter name of payer for Visa/MasterCard transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
///
///  @param cardnumber Enter the Visa/MasterCard cardnumber<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
///
///  @param cvv Enter the Visa/MasterCard cvv<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
///
///  @param exp Enter the Visa/MasterCard expiry date in the format MM/YYYY e.g 07/2030<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
///
///  @param currency Enter the currency you intend to make the transaction for Visa/MasterCard based transactions<p style=\"color:red\">This method applies for request method <b>cardaccept</b></p> (optional)
///
///  @param account Enter the Pesamoni account you would like to use for this transaction<p style=\"color:red\">This method applies for request method <b>paybills</b></p> (optional)
///
///  @param reference Enter your user generated transaction reference<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, transactionstatus, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
///
///  @param genericmsg Enter your user generated generic message for the requested transaction<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
///
///  @param token Enter your user generated token for the above mentioned method<p style=\"color:red\">This method applies for request methods <b>acreceive, acreceivekeac, acsend, acsendkeac, sendsms, sendairtime, pesab2c, sendsms, cardaccept</b></p> (optional)
///
///  @param bouquet Enter the bouquet or package you would like to pay for<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
///
///  @param payoption Enter your prefered payment option<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
///
///  @param meternumber Enter the meter number for the intended payment<p style=\"color:red\">This method applies for request methods <b>paybills</b></p> (optional)
///
///  @returns PSMInlineResponse200*
///
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
    completionHandler: (void (^)(PSMInlineResponse200* output, NSError* error)) handler {
    // verify the required parameter 'method' is set
    if (method == nil) {
        NSParameterAssert(method);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"method"] };
            NSError* error = [NSError errorWithDomain:kPSMDefaultApiErrorDomain code:kPSMDefaultApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }


    NSMutableString* resourcePath = [NSMutableString stringWithFormat:@"/transactions"];

    NSMutableDictionary *pathParams = [[NSMutableDictionary alloc] init];

    NSMutableDictionary* queryParams = [[NSMutableDictionary alloc] init];
    if (method != nil) {
        queryParams[@"method"] = method;
    }

    NSMutableDictionary* headerParams = [NSMutableDictionary dictionaryWithDictionary:self.apiClient.configuration.defaultHeaders];
    [headerParams addEntriesFromDictionary:self.defaultHeaders];
    // HTTP header `Accept`
    NSString *acceptHeader = [self.apiClient.sanitizer selectHeaderAccept:@[]];
    if(acceptHeader.length > 0) {
        headerParams[@"Accept"] = acceptHeader;
    }

    // response content type
    NSString *responseContentType = [[acceptHeader componentsSeparatedByString:@", "] firstObject] ?: @"";

    // request content type
    NSString *requestContentType = [self.apiClient.sanitizer selectHeaderContentType:@[]];

    // Authentication setting
    NSArray *authSettings = @[@"apipassword", @"apiusername"];

    id bodyParam = nil;
    NSMutableDictionary *formParams = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *localVarFiles = [[NSMutableDictionary alloc] init];

    return [self.apiClient requestWithPath: resourcePath
                                    method: @"POST"
                                pathParams: pathParams
                               queryParams: queryParams
                                formParams: formParams
                                     files: localVarFiles
                                      body: bodyParam
                              headerParams: headerParams
                              authSettings: authSettings
                        requestContentType: requestContentType
                       responseContentType: responseContentType
                              responseType: @"PSMInlineResponse200*"
                           completionBlock: ^(id data, NSError *error) {
                                if(handler) {
                                    handler((PSMInlineResponse200*)data, error);
                                }
                            }];
}



@end
