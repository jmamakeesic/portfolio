/*
  Source:
  http://www.lisenme.com/email-subscription-popup-website-using-jquery/
*/

function subscriptionPopup(){
    // get the popup
    var popup = $('#popupBox');

    // open the popup
    popup.show();

    // close the popup once close element is clicked
    $(".close").on('click',function(){
        popup.hide();
    });

    // close the popup when user clicks outside of the box
    $(window).on('click', function(e) {
        if(e.target == popup[0]){
            popup.hide();
        }
    });
}

$(document).ready(function() {
    var popDisplayed = $.cookie('popDisplayed');
    if(popDisplayed == '1'){
        return false;
    }else{
        setTimeout( function() {
            subscriptionPopup();
        },2000);
        $.cookie('popDisplayed', '1', { expires: 7 });
    }
});
