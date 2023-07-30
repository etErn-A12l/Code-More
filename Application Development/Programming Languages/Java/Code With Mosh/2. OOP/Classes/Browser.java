public class Browser {
    
    public void navigate(String url) {

        String ip = getIPAddress(url);
        String html = getWebHtml(ip);
        System.out.println(html);
    }

    private String getWebHtml(String ip) {
        return "<html><head><title>Your WebHtml</title></head><body><h1>Your WebHtml</h1></body></html>";
    }

    private String getIPAddress(String url) {
        return "127.0.0.1";
    }
}
