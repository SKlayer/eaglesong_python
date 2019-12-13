import eaglesong_hash
import binascii

Nonce1 = "00c904bd"
Nonce2 = "000000000000000000114026"
nonce = Nonce1 + Nonce2
headerHash = "d5a74fba920ad0d35ec5726f26327547cbc82180e356e5ccf6cf2e6bd75f8a66"
headerHashWithNonce = headerHash + nonce
print(headerHashWithNonce)
print("d5a74fba920ad0d35ec5726f26327547cbc82180e356e5ccf6cf2e6bd75f8a6600c904bd000000000000000000114026")
input_bytes = bytes.fromhex(headerHashWithNonce)
result = eaglesong_hash.hash(input_bytes)
if binascii.b2a_hex(result) == b'000034965758f32a266558876abba7be3ea343086bf048c9fc3c854e77a2f360':
    print("Pass")
else:
    print("Fail")