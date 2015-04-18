
# Examples And Frequently Asked Questions

## Buffers

### Create a buffer of 32 bits and initialize it.

    fapi2::buffer<uint32_t> data(0xAA55FFAA);

### Flip bit 0

    data.flipBit<0>();

### Invert the buffer

    data.invert();

### Reset it's value

    data = 0xFFFFFFFF;

### Create a mask using an anonymous object

    my_buffer &= buffer<T>().setBit<B>.invert();

### Create an 8 bit buffer, initialize it, and flip some bits around

    fapi2::buffer<uint8_t>(0xA5).flipBit<5>().flipBit<5>() == 0xA5;

## Operations and Things
### Is the FAPI_TRY / 'fapi_try_exit:' method, the recommended method for doing put/getscoms?

Yes, FAPI_TRY is the preferred wrapper for put/get scom as well as other operations which used to do the do/while/break dance based on the fapi return code.
A thread-local fapi return code, fapi2::current_err has been introduced to help with the housekeeping.

Feel free to decompose the FAPI_TRY pattern if you have clean up requirements which make FAPI_TRY too simplistic.


## Targets

### Create a processor target

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> A(PROCESSOR_CHIP_A);

### Define a function which takes only a processor as an argument, enforced by the compiler

    void takesProc( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& V );

### How do I pass TARGET_TYPE_X into putScom?

It should "just work." fapi2::putScom is defined as a template.
Basically any TargetType will match. So,

    Target<TARGET_TYPE_XBUS> foo;
    Target<TARGET_TYPE_ABUS> bar;

will both match fapi::putScom in it's more generic sense. However, platforms
might specialize the hw_access templates. For example, if the operation to
perform a putScom on an XBUS is different than accessing other targets, the
platform needs to specialize for XBUS.

    template<>
    fapi2::ReturnCode fapi2::putScom (const fapi2::Target<TARGET_TYPE_XBUS> &i_target, const uint64_t i_address, buffer< uint64_t > &i_data)
    {
        // Do XBUS special code here.
    }

### How do I get <information> with the new targets when this used to be an attribute look up before?

This question came up in the context of ATTR_CHIP_UNIT_POS, but really applies for any information
previously tucked away in attributes.

Do the attribute lookup, the platform can optimize the look up away. In any event the get_attr macro/call will always do the right thing.

If the platform can resolve the lookup without looking anything up (all the information is encoded in the value of the target) the attribute
mechanism can simply do that manipulation at compile time.

For the smaller platforms, we discussed attribute look ups were templates which could be (would be?) specialized per attribute "key."
In this way, the "look up" for the unit position could be coded to be nothing more than a static manipulation of the target value.
A look up would, obviously, be needed if the unit position (or any other attribute value) couldn't be resolved from the target value alone.

### Target Types

#### How do I write a procedure which takes multiple target types?

Depends on what you mean.

##### If you mean "I have a procedure which is generic but only for a subset of types":

    fapi2::ReturnCode newProcedure( const fapi2::Target<TARGET_TYPE_XBUS | TARGET_TYPE_ABUS> & i_target, ...);

Note that newProcedure can not then say "if xbus, do this, if abus do the
other." This is the static equivilent of grabbing a "base class" and the same
rules apply - if the method is not generic for all the subclasses, you need to
specialize for those subclasses.

__Think twice about using this mechanism. It creates a new type (the or of the
target types) and reduces the input to this type. There is no support for run
time type conversion, and so the original type is not available in this scope.__

##### If you mean "I have a procedure and I want it to do different things for different target types":

You can create templates:

    template<fapi2::TargetType T>
    void newProcedure( const fapi2::Target<T>& i_target );

    template<>
    void newProcedure( const fapi2::Target<TARGET_TYPE_XBUS>& i_target )
    {
        // XBUS specific code here
    }

    template<>
    void newProcedure( const fapi2::Target<TARGET_TYPE_ABUS>& i_target )
    {
        // ABUS specific code here
    }

Notice that because the generic case for newProcedure is declared but
never defined you will get an error at compile time if newProcedure is
called with a type other than XBUS or ABUS.

Or overloaded functions:

    void newProcedure( const fapi2::Target<TARGET_TYPE_XBUS>& i_target )
    {
        // XBUS specific code here
    }

    void newProcedure( const fapi2::Target<TARGET_TYPE_ABUS>& i_target )
    {
        // ABUS specific code here
    }

##### If you mean "I have a procedure which is mostly generic but I need special handling for some target types":

More or less the same as above, but define the generic template. There is no equivilent for
overloaded functions unless a composite target will suit your needs.

    template<fapi2::TargetType T>
    void newProcedure( const fapi2::Target<T>& i_target )
    {
        // Code for types other than ABUS or XBUS
    }

    template<>
    void newProcedure( const fapi2::Target<TARGET_TYPE_XBUS>& i_target )
    {
        // XBUS specific code here
    }

    template<>
    void newProcedure( const fapi2::Target<TARGET_TYPE_ABUS>& i_target )
    {
        // ABUS specific code here
    }

##### If you want to build a procedure which takes all target types:

__It is recomended that you do not use TARGET_TYPE_ALL - that will reduce the
type of the passed in target to the "top level base class" of targets and
every procedure called will need to be completly generic. This is probably
not what you inteded (but is sometimes useful.) Rather, it is recomended
that you simply make a generic template.__

    template<fapi2::TargetType T>
    void newProcedure( const fapi2::Target<T>& i_target )
    {
        // Code for all types
        fapi2::putScom(i_target, ... );
    }

Note that the putScom here will always be the correct putScom for the
target type passed in. Assuming procedures called in this method have
been specialized for specific target types, the compiler will find the
best match and call it.

#### Once I'm in newProcedure, what is the type of the target?

If you used a generic or specialized template, the type will be the type
of the target passed in. If you used a composite type (or'd together target
types) then the type will be TYPE_A | TYPE_B.

Notice there's no simple way to know the original type was TYPE_A in this
case. If you think about this, it makes sense. Consider:

    void f(double x);

    int y = 3;
    f(y);

There's no way in f() to know that x started life as an int, which happened to
be cast to a double.

Targets are the same thing - they're just types we create on the fly. So all of
the usual C++ tools to deal with this are available.

#### So, wait - I can't write a procedure which handles multiple target types?

You can. What you can't do is figure out the type of the object prior to
the cast. So what you need to do is make sure the original type isn't lost,
and that means you can't use TYPE_A | TYPE_B:

##### Specialize. This is the prefered mechanism.
The template and overload examples above show how to do this specialization.
It will create very regular and easy to maintain code.

##### Create a generic template and handle each type yourself.

    template<fapi2::TargetType T>
    void newProcedure( fapi2::Target<T> i_target )
    {
        // If this procedure isn't generic, check for allowed types here.
        static_assert(fapi2::is_same<T, fapi2::TARGET_TYPE_ABUS>() || fapi2::is_same<T, fapi2::TARGET_TYPE_XBUS>(),
                      "newProcedure only takes X/A busses");

        :
        :

        if (fapi2::is_same<T, fapi2::TARGET_TYPE_ABUS>())
        {
            // ABUS code
        }

        if (fapi2::is_same<T, fapi2::TARGET_TYPE_XBUS>())
        {
            // XBUS code
        }

        :
        :
    }

newProcedure is a generic template, any target type will match. And, the type T of i_target is
the original value of the target - the template matched without a cast because it's generic.
However, with that generality we lost the compiler argument type checking so we replace it with
the static_assert. This happens at compile time so the compiler will complain if a target other
than an XBUS or ABUS is passed in to this procedure. To handle the special cases for the types,
fapi2::is_same is used again - and is also a compile time operation. And so when this template
matches an XBUS target, the code generated is specific to the XBUS target.

#### Ok, so what is TARGET_TYPE_X | TARGET_TYPE_Y for then?

Creating procedures which are generic to those types. Think of this as a base
class method.
