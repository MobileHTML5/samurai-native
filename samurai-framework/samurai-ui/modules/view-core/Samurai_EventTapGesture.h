//
//     ____    _                        __     _      _____
//    / ___\  /_\     /\/\    /\ /\    /__\   /_\     \_   \
//    \ \    //_\\   /    \  / / \ \  / \//  //_\\     / /\/
//  /\_\ \  /  _  \ / /\/\ \ \ \_/ / / _  \ /  _  \ /\/ /_
//  \____/  \_/ \_/ \/    \/  \___/  \/ \_/ \_/ \_/ \____/
//
//	Copyright Samurai development team and other contributors
//
//	http://www.samurai-framework.com
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//

#import "Samurai_Core.h"
#import "Samurai_Event.h"
#import "Samurai_UIConfig.h"

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#pragma mark -

typedef enum
{
	TapState_Idle = 0,
	TapState_Pressing,
	TapState_Moving,
	TapState_Raised,
	TapState_Cancelled
} TapState;

#pragma mark -

@interface UIView(EventTapGesture)

@joint( tapStateChanged );

@signal( eventTapPressing );	/// 按下
@signal( eventTapMoving );		/// 移动
@signal( eventTapRaised );		/// 抬起
@signal( eventTapCancelled );	/// 取消

@prop_strong( NSString *,	tapSignalName );
@prop_readonly( TapState,	tapState );
@prop_readonly( BOOL,		tapPressing );
@prop_readonly( BOOL,		tapMoving );
@prop_readonly( BOOL,		tapRaised );
@prop_readonly( BOOL,		tapCancelled );

- (void)enableTapGesture;
- (void)enableTapGestureWithSignal:(NSString *)signal;

- (void)disableTapGesture;

@end

#endif	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
