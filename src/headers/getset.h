#ifndef GETSET_H
#define GETSET_H

#define GETSET(Type, MemberName, FaceName) \
            Type Get##FaceName() const { \
                return MemberName; \
          }; \
          void Set##FaceName(Type value) { \
                MemberName = value; \
}


#endif
