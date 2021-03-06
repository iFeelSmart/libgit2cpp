#include "git2cpp/reference.h"

#include <git2/refs.h>

#include <cassert>
#include <utility>

namespace git
{
    void Reference::Destroy::operator()(git_reference* ref) const
    {
        git_reference_free(ref);
    }

    Reference::Reference(git_reference * ref)
        : ref_(ref)
    {
    }

    const char * Reference::name() const
    {
        return git_reference_name(ptr());
    }

    git_ref_t Reference::type() const
    {
        return git_reference_type(ptr());
    }

    git_oid const & Reference::target() const
    {
        assert(type() != GIT_REF_SYMBOLIC);
        return *git_reference_target(ptr());
    }

    const char * Reference::symbolic_target() const
    {
        return git_reference_symbolic_target(ptr());
    }
}
