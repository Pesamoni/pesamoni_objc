#import <Foundation/Foundation.h>

@class PSMApiClient;


@protocol PSMApi <NSObject>

@property(readonly, nonatomic, strong) PSMApiClient *apiClient;

-(instancetype) initWithApiClient:(PSMApiClient *)apiClient;

-(void) setDefaultHeaderValue:(NSString*) value forKey:(NSString*)key;
-(NSString*) defaultHeaderForKey:(NSString*)key;

-(NSDictionary *)defaultHeaders;

@end
