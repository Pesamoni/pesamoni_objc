#import <Foundation/Foundation.h>




/**
 * A key for deserialization ErrorDomain
 */
extern NSString *const PSMDeserializationErrorDomainKey;

/**
 * Code for deserialization type mismatch error
 */
extern NSInteger const PSMTypeMismatchErrorCode;

/**
 * Code for deserialization empty value error
 */
extern NSInteger const PSMEmptyValueOccurredErrorCode;

/**
 * Error code for unknown response
 */
extern NSInteger const PSMUnknownResponseObjectErrorCode;

@protocol PSMResponseDeserializer <NSObject>

/**
 * Deserializes the given data to Objective-C object.
 *
 * @param data The data will be deserialized.
 * @param className The type of objective-c object.
 * @param error The error
 */
- (id) deserialize:(id) data class:(NSString *) className error:(NSError**)error;

@end

@interface PSMResponseDeserializer : NSObject <PSMResponseDeserializer>

/**
 *  If an null value occurs in dictionary or array if set to YES whole response will be invalid else will be ignored
 *  @default NO
 */
@property (nonatomic, assign) BOOL treatNullAsError;

@end
