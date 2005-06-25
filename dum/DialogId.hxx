#if !defined(RESIP_DIALOG_ID_HXX)
#define RESIP_DIALOG_ID_HXX

#include "rutil/Data.hxx"
#include "dum/DialogSetId.hxx"

namespace resip
{

class DialogId
{
   public:
      DialogId(const SipMessage& msg );
      DialogId(const Data& callId, const Data& localTag, const Data& remoteTag );
      DialogId(const DialogSetId& id, const Data& remoteTag );
      
      bool operator==(const DialogId& rhs) const;
      bool operator!=(const DialogId& rhs) const;
      bool operator<(const DialogId& rhs) const;

      const DialogSetId& getDialogSetId() const;

      const Data& getCallId() const;
      const Data& getLocalTag() const;
      const Data& getRemoteTag() const;

      size_t hash() const;

#if defined(HASH_MAP_NAMESPACE)
      friend struct HASH_MAP_NAMESPACE::hash<resip::DialogId>;
#elif defined(__INTEL_COMPILER )
      friend size_t hash_value(const resip::DialogId& id);
#endif

   private:
      friend std::ostream& operator<<(std::ostream&, const DialogId& id);
      DialogSetId mDialogSetId;
      Data mRemoteTag;
};
}
#if defined(HASH_MAP_NAMESPACE)
namespace HASH_MAP_NAMESPACE
{

template<>
struct hash<resip::DialogId>
{
      size_t operator()(const resip::DialogId& id) const;
};

}
#elif defined(__INTEL_COMPILER)
namespace std { size_t hash_value(const resip::DialogId& id); }
#endif

  
#endif

/* ====================================================================
 * The Vovida Software License, Version 1.0 
 * 
 * Copyright (c) 2000 Vovida Networks, Inc.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The names "VOCAL", "Vovida Open Communication Application Library",
 *    and "Vovida Open Communication Application Library (VOCAL)" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact vocal@vovida.org.
 *
 * 4. Products derived from this software may not be called "VOCAL", nor
 *    may "VOCAL" appear in their name, without prior written
 *    permission of Vovida Networks, Inc.
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL VOVIDA
 * NETWORKS, INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 * IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by Vovida
 * Networks, Inc. and many individuals on behalf of Vovida Networks,
 * Inc.  For more information on Vovida Networks, Inc., please see
 * <http://www.vovida.org/>.
 *
 */
