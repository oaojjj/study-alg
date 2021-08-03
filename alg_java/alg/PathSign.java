package alg;

/**
 * Path Sign
 * PATHWAY : 지나갈 수 있는 경로
 * WALL : 못지나가는 경로
 * BLOCKED : 출구가 없는 경로
 * PATH : 출구로 가는 길이 존재할 수 있는 경로(이미 지나온 길)
 * EXIT : 출구
 */
public enum PathSign {
    PATHWAY, WALL, PATH, BLOCKED, EXIT
}