#pragma once

#include <yt/yt/client/driver/driver.h>

#include <CXX/Extensions.hxx> // pycxx

namespace NYT::NPython {

////////////////////////////////////////////////////////////////////////////////

class TCommandDescriptor
    : public Py::PythonClass<TCommandDescriptor>
{
public:
    TCommandDescriptor(Py::PythonClassInstance *self, Py::Tuple& args, Py::Dict& kwargs);

    void SetDescriptor(const NDriver::TCommandDescriptor& descriptor);

    Py::Object InputType(Py::Tuple& args, Py::Dict& kwargs);
    PYCXX_KEYWORDS_METHOD_DECL(TCommandDescriptor, InputType)

    Py::Object OutputType(Py::Tuple& args, Py::Dict& kwargs);
    PYCXX_KEYWORDS_METHOD_DECL(TCommandDescriptor, OutputType)

    Py::Object IsVolatile(Py::Tuple& args, Py::Dict& kwargs);
    PYCXX_KEYWORDS_METHOD_DECL(TCommandDescriptor, IsVolatile)

    Py::Object IsHeavy(Py::Tuple& args, Py::Dict& kwargs);
    PYCXX_KEYWORDS_METHOD_DECL(TCommandDescriptor, IsHeavy)

    virtual ~TCommandDescriptor();

    static void InitType(const TString& moduleName);

private:
    NDriver::TCommandDescriptor Descriptor_;

    static TString TypeName_;
};

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NPython
