#import <Foundation/Foundation.h>




#ifndef PSMDebugLogResponse
#define PSMDebugLogResponse(response, responseObject,request, error) [[PSMLogger sharedLogger] logResponse:response responseObject:responseObject request:request error:error];
#endif

/**
 * Log debug message macro
 */
#ifndef PSMDebugLog
#define PSMDebugLog(format, ...) [[PSMLogger sharedLogger] debugLog:[NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__] message: format, ##__VA_ARGS__];
#endif

@interface PSMLogger : NSObject

+(instancetype)sharedLogger;

/**
 * Enabled switch, default NO - default set by PSMConfiguration debug property
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 * Debug file location, default log in console
 */
@property (nonatomic, strong) NSString *loggingFile;

/**
 * Log file handler, this property is used by sdk internally.
 */
@property (nonatomic, strong, readonly) NSFileHandle *loggingFileHandler;

/**
 * Log debug message
 */
-(void)debugLog:(NSString *)method message:(NSString *)format, ...;

/**
 * Logs request and response
 *
 * @param response NSURLResponse for the HTTP request.
 * @param responseObject response object of the HTTP request.
 * @param request   The HTTP request.
 * @param error     The error of the HTTP request.
 */
- (void)logResponse:(NSURLResponse *)response responseObject:(id)responseObject request:(NSURLRequest *)request error:(NSError *)error;

@end
