#import "PSMInlineResponse200.h"

@implementation PSMInlineResponse200

- (instancetype)init {
  self = [super init];
  if (self) {
    // initialize property's default value, if any
    
  }
  return self;
}


/**
 * Maps json key to property name.
 * This method is used by `JSONModel`.
 */
+ (JSONKeyMapper *)keyMapper {
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"status": @"status", @"token": @"token", @"_description": @"description", @"mobile": @"mobile", @"statuscode": @"statuscode", @"transactionType": @"transaction_type" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"status", @"token", @"_description", @"mobile", @"statuscode", @"transactionType"];
  return [optionalProperties containsObject:propertyName];
}

@end
