# PBL2. DỰ ÁN CƠ SỞ LẬP TRÌNH
## Đề tài: QUẢN LÝ THÔNG TIN VÀ TÍNH LÃI CỦA SỔ TIẾT KIỆM
### Hệ thống có hai cấp độ phân quyền: Người dùng hệ thống và người quản trị hệ thống.
Mỗi cấp độ phân quyền có những chức năng và quyền hạn riêng biệt trong hệ thống.
#### 1. Đối tượng người dùng: 
- Đăng nhập, đăng ký tài khoản:
+ Đăng nhập tài khoản: Người dùng có thể đăng nhập với tên đăng nhập và mật khẩu nếu đã có sẵn tải khoản trong hệ thống. Khi đăng nhập, chương trình yêu cầu người dùng nhập tên đăng nhập và mật khẩu. Sau đó, nó kiểm tra xem thông tin đăng nhập có khớp với thông tin đã đăng ký trước đó trên hệ thống hay không. Nếu thông tin đúng, hệ thống thông báo đăng nhập thành công. Ngược lại, thông báo rằng thông tin đăng nhập không chính xác và yêu cầu người dùng nhập lại.
+ Đăng ký tài khoản: Nếu chưa có tài khoản, người dùng có thể tạo một tài khoản mới. Chương trình yêu cầu người dùng nhập tên đăng nhập và mật khẩu. Nếu tên đăng nhập đã được sử dụng trước đó, chương trình sẽ hiển thị thông báo và yêu cầu người dùng nhập tên đăng nhập khác. Nếu chưa được sử dụng, chương trình tiếp tục yêu cầu người dùng điền thông tin cá nhân để mở tài khoản. Sau khi tạo tài khoản thành công, tài khoản sẽ được lưu vào hệ thống và người dùng có thể đăng nhập vào những lần sử dụng tiếp theo.
- Các chức năng khi sử dụng hệ thống với tư cách người dùng:
+ Chức năng xem thông tin người dùng: Cho phép người dùng xem thông tin cá nhân mà họ đã đăng ký trên hệ thống. Thông tin bao gồm: họ và tên người dùng, số căn cước công dân, địa chỉ tạm trú và số điện thoại.
+ Chức năng mở sổ tiết kiệm có kỳ hạn: Cho phép người dùng tạo ra tài khoản tiết kiệm mới với một kỳ hạn cụ thể. Chương trình yêu cầu người dùng chọn kỳ hạn của sổ và nhập số tiền muốn gửi vào sổ, đồng thời chương trình cũng lưu lại ngày lập sổ.
+ Chức năng mở sổ tiết kiệm không kỳ hạn: Người dùng có thể chọn mở một sổ tiết kiệm không kỳ hạn, loại tài khoản tiết kiệm này thường có lãi suất thấp hơn so với tài khoản có kỳ hạn. Chương trình cũng yêu cầu người dùng nhập vào số tiền gửi và lưu lại ngày lập sổ.
+ Chức năng xem tất cả sổ tiết kiệm mà người dùng hiện có: Người sử dụng có thể xem thông tin chi tiết về từng sổ tiết kiệm (bao gồm cả sổ tiết kiệm có kỳ hạn và không kỳ hạn).
+ Chức năng rút tiền thông qua mã ID của sổ: Người sử dụng có thể rút tiền từ sổ tiết kiệm thông qua nhập mã ID của sổ, hệ thống sẽ thực hiện giao dịch sau khi xác minh thành công. Sau khi người dùng rút tiền, chương trình sẽ xóa sổ đó ra khỏi danh sách sổ tiết kiệm của người dùng.
#### 2. Đối tượng người quản lý
- Đăng nhập tài khoản: Tương tự với người dùng hệ thống, người quản trị có thể đăng nhập với tư cách quản trị với tài khoản đã được lưu sẵn trong bộ nhớ chương trình.
- Các chức năng khi sử dụng hệ thống với tư cách người quản lý:
+ Chức năng xem thông tin của tất cả tài khoản người dùng hiện có trong hệ thống: Hiển thị toàn bộ thông tin cá nhân mà người dùng đã của tất cả tài khoản người dùng hiện có trong hệ thống.
+ Chức năng tìm kiếm thông tin người dùng thông qua mã ID tài khoản: Chương trình yêu cầu nhập mã ID tài khoản. Nếu mã ID hợp lệ thì hiển thị thông tin cá nhân của người ứng với mã ID đó, ngược lại yêu cầu nhập lại.
+ Chức năng xóa tài khoản người dùng thông qua mã ID tài khoản: Cho phép người quản lý xóa tài khoản của 1 người dùng nếu có yêu cầu hoặc nếu tài khoản đó vi phạm điều kiện sử dụng của hệ thống. Khi 1 tài khoản bị xóa, toàn bộ sổ tiết kiệm (bao gồm sổ có kỳ hạn và sổ không kỳ hạn) mà người dùng đã lập đều sẽ bị xóa. Chương trình yêu cầu nhập ID tài khoản cần xóa, sau đó hệ thống sẽ xóa tài khoản đó sau khi xác minh thành công.
+ Chức năng thống kê các sổ tiết kiệm thông qua năm nhập vào: Chương trình yêu cầu nhập năm muốn thống kê. Nếu năm hợp lệ thì hiển thị thông tin chi tiết về từng sổ tiết kiệm (bao gồm cả sổ tiết kiệm có kỳ hạn và không kỳ hạn) và tổng lãi suất của các sổ được mở vào năm vừa nhập tính đến thời điểm hiện tại.

### Made by Thanh Tu and Ai Tran
