#ifndef __CUSTOM_CLASS_H__
#define __CUSTOM_CLASS_H__

class CUSTOM_CLASS
{
public:
    CUSTOM_CLASS();
    CUSTOM_CLASS(const CUSTOM_CLASS&);
    ~CUSTOM_CLASS();

    CUSTOM_CLASS& operator=(const CUSTOM_CLASS&);
};

#endif